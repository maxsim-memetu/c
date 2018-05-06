#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc, char *argv[])
{
    int clientfd = -1;
    int dummyfd = -1;
    int maxfd = -1;
    struct sockaddr_in server_addr;

    char recv_buf[100] = {0};
    int msg_len = 0;
    int bytes_recv = 0;
    fd_set readfd;
    int retval = 0;


    /* Open the socket and a dummy socket */
    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    dummyfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == clientfd || -1 == dummyfd)
    {
        perror("socket error: ");
        exit(1);
    }
    printf("Socket opened : %d\n", clientfd);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2002);
    //server_addr.sin_addr.s_addr = INADDR_ANY;
    // inet_aton(argv[1], &(server_addr.sin_addr));
    char* lip = "";
    inet_aton("127.0.0.1", &(server_addr.sin_addr));
    memset(&(server_addr.sin_zero), 0, 8);

    /* Connect to server */
    if(connect(clientfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)))
    {
        perror("connect error: ");
        exit(1);
    }
    printf("Connect Success\n");
    maxfd = (clientfd > dummyfd) ? (clientfd + 1) : (dummyfd + 1);
    send(clientfd, "fname\n", 7, 0);
    while(1)
    {
        FD_ZERO(&readfd);
        FD_SET(clientfd, &readfd);
        FD_SET(dummyfd, &readfd);
        printf("Wait on select\n");
        retval = select(maxfd , &readfd, NULL, NULL, NULL);
        printf("return value from server:%i\n", retval);
        if(retval <= 0)
        {
            printf("select failed\n");
        }
        else if (FD_ISSET(clientfd, &readfd)) {
        
            printf("Wait on recv\n");
            /* ... The process waits here ... */
            bytes_recv = recv(clientfd, recv_buf, 100, 0);
            printf("%d: Bytes recv = %d\t%s\n", retval, bytes_recv, recv_buf);
            memset(recv_buf, 0 ,100);
            if(bytes_recv == 0){break;}
        } else {
            printf("not clientfd?\n");
        }
    }

    close(clientfd);
    return 0;
}