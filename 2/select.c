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
    int count, createsocket, chunks, newsocket[5], i;
    int bufsize = 2048;
    char *buffer = malloc(bufsize);
    char fname[256];
    struct sockaddr_in address;
    fd_set master;
    fd_set read_fds;
    int fdmax, j; 

    FD_ZERO(&master);
    FD_ZERO(&read_fds);

    if((createsocket = socket(AF_INET, SOCK_STREAM, 0)) > 0)
    {
        printf("Socket created.\n");
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    printf("argv %s", argv[1]);
    inet_pton(AF_INET, argv[1], &address.sin_addr);


    if(connect(createsocket, (struct sockaddr*)&address, sizeof(address)) == 0)
    {
        printf("Connected to server %s\n",argv[1]);
    }

    printf("Enter the file name to download\n");
    scanf("%s",fname);

    send(createsocket, fname, sizeof(fname), 0);

//    printf("Enter the chunks of file to receive");
    printf("waiting to receive the file from server..\n");

    //code to create a new socket based on the number of chunks required

    // for(i=0;i<4;i++)
    // {
    //     if((newsocket[i] = socket(AF_INET, SOCK_STREAM, 0)) > 0)
    //     {
    //             printf("new Socket %d created.\n", i);
    //     }
    // }

    FD_SET(createsocket, &master);
    fdmax = createsocket;

    for(;;)
    {
        read_fds = master;
        if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){
            perror("select");
            exit(2);
        }
        if(FD_ISSET(0))
        // for(i=0; i<=fdmax; i++){
        //     if(FD_ISSET(i, &read_fds)) {
        //         if(i == createsocket) {
        //             printf("something is happening..\n");

        //             if(newsocket[i] == -1){
        //                 printf("socket %d\n",i);
        //             } else {
        //                 FD_SET(newsocket[i], &master);
        //                 if(newsocket[i] > fdmax) {
        //                     fdmax = newsocket[i];
        //                 }
        //                 printf("still something is going on..\n");
        //             }
        //         } else {
        //             printf("Doing something..\n");
        //             for(j = 0; j <= fdmax; j++) {
        //                 if(FD_ISSET(j, &master)) {
        //                     if(j!= createsocket && j!= i) {
        //                         if((count = recv(createsocket, buffer, bufsize, 0)) > 0) {
        //                             perror("recv");
        //                         } else {
        //                             write(1, buffer, count);
        //                         }

        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
    }



//    while((count = recv(createsocket, buffer, bufsize, 0)) > 0)
//        write(1, buffer, count);

    printf("EOF.\n");

    for(i=0;i<4;i++)
    {
        close(newsocket[i]);
    }
    return close(createsocket);
}