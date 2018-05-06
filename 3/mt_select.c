# include <pthread.h>
# include <stdio.h>
# include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>

# define NTH 40
# define NFD 50
void start_fn(){
	pthread_t tid;
	tid = pthread_self();
	printf("in thread %u start function\n", (unsigned int)tid);
	int k=0;
	// for(;k<10;k++){
	// 	printf("%u\n", (unsigned int)tid);
	// 	sleep(1);
	// }
    int clientfd = -1;
    // int dummyfd = -1;
    int maxfd = -1;
    struct sockaddr_in server_addr;

    char recv_buf[100] = {0};
    int msg_len = 0;
    int bytes_recv = 0;
    fd_set readfd;
    int retval = 0;

    int fds[NFD], i;
    for(i=0;i<NFD;i++){
        fds[i] = socket(AF_INET, SOCK_STREAM, 0);
        if(-1 == fds[i]){
            printf("failed to alloc socket\n");
            exit(1);
        }
    }
    /* Open the socket and a dummy socket */
    // clientfd = socket(AF_INET, SOCK_STREAM, 0);
    // // dummyfd = socket(AF_INET, SOCK_STREAM, 0);
    // // if(-1 == clientfd || -1 == dummyfd)
    // if(-1 == clientfd)
    // {
    //     perror("socket error: ");
    //     exit(1);
    // }
    // printf("Socket opened : %d\n", clientfd);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2002);
    //server_addr.sin_addr.s_addr = INADDR_ANY;
    inet_aton("127.0.0.1", &(server_addr.sin_addr));
    memset(&(server_addr.sin_zero), 0, 8);

    /* Connect to server */
    // if(connect(clientfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)))
    // {
    //     perror("connect error: ");
    //     exit(1);
    // }
    // printf("Connect Success\n");
    for(i=0;i<NFD;i++){
        if(connect(fds[i], (struct sockaddr *)&server_addr, sizeof(struct sockaddr)))
        {
            perror("connect error: ");
            exit(1);
        }
        maxfd = (fds[i] > maxfd) ? fds[i] : maxfd;
        printf("fd %d sending\n", fds[i]);
        send(fds[i], "fname\n", 7, 0);
    }
    // maxfd = (clientfd > dummyfd) ? (clientfd + 1) : (dummyfd + 1);
    // maxfd = clientfd + 1;
    // send(clientfd, "fname\n", 7, 0);

    while(1)
    {
        FD_ZERO(&readfd);
        for(i=0;i<NFD;i++){
            FD_SET(fds[i], &readfd);
        }
        // FD_SET(dummyfd, &readfd);
        printf("Wait on select\n");
        retval = select(maxfd , &readfd, NULL, NULL, NULL);
        printf("select ret = %i\n", retval);
        if(retval <= 0) {
            printf("select failed\n");
        } else {
            for(i=0;i<NFD;i++){
                if (FD_ISSET(fds[i], &readfd)){
                    printf("receiving from fd %d\n", fds[i]);
                    bytes_recv = recv(fds[i], recv_buf, 100, 0);
                    printf("retval=%d | Bytes recv = %d\t| content = %s\n", retval, bytes_recv, recv_buf);
                    memset(recv_buf, 0 ,100);
                    if(bytes_recv <= 0){
                        close(fds[i]);
                        fds[i] = socket(AF_INET, SOCK_STREAM, 0);
                        if(-1 == fds[i]){
                            perror("socket error: ");
                            exit(1);
                        }
                        printf("fd opened : %d\n", fds[i]);
                        if(connect(fds[i], (struct sockaddr *)&server_addr, sizeof(struct sockaddr))) {
                            perror("connect error: ");
                            exit(1);
                        }
                        printf("reconnect Success\n");
                        maxfd = (maxfd > fds[i]) ? maxfd : fds[i];
                        printf("fd %d sending again\n", fds[i]);
                        send(fds[i], "fname\n", 7, 0);
                        continue;
                    }
                }
            }

        // } else {
        //     // FD_SET(clientfd, &readfd);
        //     printf("not clientfd? %d\n", retval);
        }
    }
    printf("returning from start_fn\n");
    // close(clientfd);
    // return 0;
}

int main(){
	pthread_t* pa = (pthread_t)malloc(sizeof(pthread_t)*2);
	// pthread_attr_t attr;
	// PTHREAD_ATTR_INIT(&attr);
	// pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	// pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	void ** rval;
	int i = 0;
	for(;i<NTH;i++){
		int rs = pthread_create(pa+i, NULL, start_fn, NULL);
		if(rs == 0){
			printf("a new thread %u is created\n", *(pa+i));
		} else {
			printf("error when create thread\n");
		}
	}
	int j=0;
	for(;j<NTH;j++){
		pthread_join(*(pa+j), rval);
	}
	printf("exiting main\n");
	return 0;
}