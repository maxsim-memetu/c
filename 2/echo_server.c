#include <sys/socket.h>       /*  socket definitions        */
#include <sys/types.h>        /*  socket types              */
#include <arpa/inet.h>        /*  inet (3) funtions         */
#include <unistd.h>           /*  misc. UNIX functions      */

#include "helper.h"           /*  our own helper functions  */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/*  Global constants  */

#define ECHO_PORT          (2002)
#define MAX_LINE           (1000)

int main(int argc, char *argv[]) {
    int       list_s;                /*  listening socket          */
    int       conn_s;                /*  connection socket         */
    short int port;                  /*  port number               */
    struct    sockaddr_in servaddr;  /*  socket address structure  */
    char      buffer[MAX_LINE];      /*  character buffer          */
    char     *endptr;                /*  for strtol()              */


    /*  Get port number from the command line, and
        set to default port if no arguments were supplied  */

    if ( argc == 2 ) {
	     port = strtol(argv[1], &endptr, 0);
      	if ( *endptr ) {
      	    fprintf(stderr, "ECHOSERV: Invalid port number.\n");
      	    exit(EXIT_FAILURE);
      	}
    }
    else if ( argc < 2 ) {
    	port = ECHO_PORT;
    }
    else {
    	fprintf(stderr, "ECHOSERV: Invalid arguments.\n");
    	exit(EXIT_FAILURE);
    }

	
    /*  Create the listening socket  */

    if ( (list_s = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
    	fprintf(stderr, "ECHOSERV: Error creating listening socket.\n");
    	exit(EXIT_FAILURE);
    }


    /*  Set all bytes in socket address structure to
        zero, and fill in the relevant data members   */

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(port);


    /*  Bind our socket addresss to the 
	listening socket, and call listen()  */

    if ( bind(list_s, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0 ) {
    	fprintf(stderr, "ECHOSERV: Error calling bind()\n");
    	exit(EXIT_FAILURE);
    }

    if ( listen(list_s, LISTENQ) < 0 ) {
  	fprintf(stderr, "ECHOSERV: Error calling listen()\n");
  	exit(EXIT_FAILURE);
    }
    printf("listening\n");
    
    /*  Enter an infinite loop to respond
        to client requests and echo input  */

    while ( 1 ) {

    	/*  Wait for a connection, then accept() it  */

    	if ( (conn_s = accept(list_s, NULL, NULL) ) < 0 ) {
    	    fprintf(stderr, "ECHOSERV: Error calling accept()\n");
    	    exit(EXIT_FAILURE);
    	}
      printf("accepted\n");

    	/*  Retrieve an input line from the connected socket
    	    then simply write it back to the same socket.     */

    	Readline(conn_s, buffer, MAX_LINE-1);
    	Writeline(conn_s, buffer, strlen(buffer));


    	/*  Close the connected socket  */

    	if ( close(conn_s) < 0 ) {
    	    fprintf(stderr, "ECHOSERV: Error calling close()\n");
    	    exit(EXIT_FAILURE);
    	}
      printf("closed connection\n");
    }
}

ssize_t Readline(int sockd, void *vptr, size_t maxlen) {
    ssize_t n, rc;
    char    c, *buffer;

    buffer = vptr;

  for ( n = 1; n < maxlen; n++ ) {
  
    if ( (rc = read(sockd, &c, 1)) == 1 ) {
        printf("reading:%c\n", c);
        *buffer++ = c;
        if ( c == '\n' ){
          printf("content:%s", buffer);
          break;
        }
    }
    else if ( rc == 0 ) {
      printf("rc==0\n");
        if ( n == 1 )
          return 0;
        else
          break;
    }
    else {
      printf("read error\n");
        if ( errno == EINTR )
          continue;
        return -1;
    }
  }
  printf("returning from readline\n");
    // *buffer = 0;
    return n;
}


/*  Write a line to a socket  */

ssize_t Writeline(int sockd, const void *vptr, size_t n) {
    size_t      nleft;
    ssize_t     nwritten;
    const char *buffer;

    buffer = vptr;
    nleft  = n;
    printf("buffer:%s | nleft:%i\n", buffer, nleft);
    while ( nleft > 0 ) {
      if ( (nwritten = write(sockd, buffer, nleft)) <= 0 ) {
        if ( errno == EINTR )
          nwritten = 0;
        else
          return -1;
      }
      printf("writen %i\n", nwritten);
      nleft  -= nwritten;
      buffer += nwritten;
    }

    return n;
}