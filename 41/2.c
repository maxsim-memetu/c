#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <time.h>
#include "util.h"
#define PORT (8848)
#define ADDR "127.0.0.1"
#define MAX_MSG_BODY 1024
#define MAX_TUBE 4

// call backs are managed in a linked list
typedef struct List {
	struct List* next;
	// struct List* prev;
	int (*hehe)(char* para);
} list;
typedef struct callBack {
	int (*haha)(char* para);
} cb;

int soso(char* para) {
	printf("in soso %s\n", para);
}
int shsh(char* para) {
	printf("in shsh %s\n", para);
}


// tube
typedef struct sCommand
{
	time_t tTimming;
	char* command_content;

} command;
typedef struct sTube {
	struct sTube* next;
	struct sTube* prev;
	char* ip;
	command* command_list_head;
} Tube;
// typedef struct sTubeList
// {
// 	Tube* tubes_head;
// } TubeList;
void add_one_tube(char* ip) {

}
void remove_one_tube(char* ip) {

}
void add_one_command_to_tube(char* ip, char* cmd) {

}
char* pop_one_command_from_tube(char* ip) {

}

// clients' messages, stored in a list, like a queue.
// messages in message_queue are malloced, and are freeed else where

typedef struct Messages {
	struct Messages* next;
	char* content;
	int fd;
} message_queue;
void add_message(char* msg_content, size_t nbyte, int client_fd, message_queue** ptr_queue_head, message_queue** ptr_queue_tail) {
	message_queue* new_message = (message_queue*)malloc(sizeof(message_queue));
	new_message->fd = client_fd;
	new_message->content = (char*)malloc(sizeof(char)*(nbyte+1));
	strcpy(new_message->content, msg_content);
	*(new_message->content + nbyte) = '\0';
	new_message->next = NULL;
	if((*ptr_queue_head == NULL) && (*ptr_queue_tail == NULL)) {
		printf("enqueue 1st msg:%s\n", msg_content);
		*ptr_queue_tail = *ptr_queue_head = new_message;
	} else{
		printf("enqueue 1 msg to queue tail: %s\n", msg_content);
		(*ptr_queue_tail)->next = new_message;
		*ptr_queue_tail = new_message;
	}
}
message_queue* dequeue_message(message_queue** ptr_queue_head, message_queue** ptr_queue_tail) {
	message_queue* ret;
	if((*ptr_queue_head == NULL) && (*ptr_queue_tail == NULL)) {
		printf("trying to dequeue an empty msg queue\n");
		return NULL;
	} else {
		ret = *ptr_queue_head;
		if(*ptr_queue_head == *ptr_queue_tail) {
			// only 1 msg
			*ptr_queue_head = *ptr_queue_tail = NULL;
		} else {
			// more than 1 msg
			*ptr_queue_head = (*ptr_queue_head)->next;
		}
		return ret;
	}
}
int delete_message(message_queue* msg) {
	//first free the char*
	free(msg->content);
	free(msg); //will this free the original msg or the local one?
}
int read_incoming_msg(int socketfd, char* buffer, int max_size) {
	int nbytes;
	printf("read_incoming_msg can read in %i bytes at most\n", max_size);
	if ((nbytes = recv(socketfd, buffer, max_size, 0)) <= 0) {
		if (nbytes == 0) {
          printf("selectserver: socket %d hung up\n", socketfd);
        } else {
          perror("recv");
        }
        return -1;
        // close(socketfd); // bye!
        // FD_CLR(socketfd, &master); // 從 master set 中移除
    } else {
    	printf("successfully read %i bytes\n", nbytes);
    	return nbytes;
	}
	// for ( n = 1; n < MAX_MSG_BODY; n++) {
	// 	if((rc = recv(socketfd, &c, 1)) == 1) {
	// 		printf("reading from socket:%c\n", c);
	// 		*buffer++ = c;
	// 	} else if( rc == 0 ) {
	// 		printf("read returns 0\n");
	// 		if(n==1)
	// 			return 0;
	// 		else
	// 			break;
	// 	} else {//error
	// 		printf("read returns error\n");
	// 		return -1;
	// 	}
	// }
}

//parse_msg, we first define a protocol between LUA and C
void parse_msg(message_queue* msg, Tube* head, Tube* tail) {
	printf("parsing msg:%s, length %i\n", msg->content, strlen(msg->content));
	char** msg_array = str_split(msg->content, ',');
	if(msg_array) {
		if(strcmp(msg_array[0], "ADD") == 0) {
				printf("add a new tube");
				add_one_tube(msg_array[1]);
		} else if(strcmp(msg_array[0], "SET") == 0) {
			printf("set parameter for an ip\n");
		} else {
			printf("default case in parse_msg\n");
		}
		int i;
		for(i=0; *(msg_array + i); i++) {
			free(*(msg_array + i));
		}
		free(msg_array);
	}
}


// take action, invoke call back




// clients are managed in a double linked list
typedef struct clientList {
	// this struct should be double link list rather than single link list, because we need to delete clients.
	struct clientList* next;
	struct clientList* prev;
	int socket;
} clients;

void add_new_client(int new_cli_fd, clients** ptr_client_head, clients** ptr_last_one) {
	clients* new_one = (clients*)malloc(sizeof(clients));
	new_one->socket = new_cli_fd;
	new_one->prev = new_one->next = NULL;
	if ((*ptr_client_head == NULL) || (*ptr_last_one == NULL)) {
		printf("adding the 1st one, FD is %i\n", new_cli_fd);
		*ptr_client_head = *ptr_last_one = new_one;
	} else {
		printf("add another client %i\n", new_cli_fd);
		(*ptr_last_one)->next = new_one; // make the former last_one's next point to the new one
		new_one->prev = *ptr_last_one;
		*ptr_last_one = new_one; // last_one step forward 1 to new_one.
	}
}
void remove_client(int client_id, clients** ptr_client_head, clients** ptr_last_one) {
	if((*ptr_client_head == NULL) || (*ptr_last_one == NULL)) {
		// empty clients list, nothing to remove
		printf("empty clients list, nothing to remove\n");
	} else {
		printf("client list has at least 1 client\n");
		// clients list has at least 1 clients
		clients* itr;
		for(itr = *ptr_client_head; itr != NULL; itr = itr->next) {
			if( itr->socket == client_id) {
				printf("we found client %i in client list\n", client_id);
				// this element is 1st and lastone
				if(itr->next == NULL && itr->prev == NULL){
					printf("this element is 1st and lastone\n");
					(*ptr_last_one) = (*ptr_client_head) = NULL;
				} else if(itr->prev == NULL && itr->next != NULL) {
					// this element is 1st but not last
					printf("this element is 1st but not last\n");
					(*ptr_client_head) = itr->next;
					itr->next->prev = NULL;
				} else if(itr->next == NULL && itr->prev != NULL) {
					// this element is last but not 1st
					printf("this element is last but not 1st\n");
					(*ptr_last_one) = itr->prev;
					itr->prev->next = NULL;
				} else {
					// this element is a middle one
					printf("this element is a middle one\n");
					itr->next->prev = itr->prev;
					itr->prev->next = itr->next;
				}
				printf("freeing client list entry\n");
				free(itr);
				break;
			}
		}
	}
}
int count_clients(clients* head, clients* tail) {
	// int cnt = 0;
	// clients* tmp = head;
	// if( tmp != NULL) {
	// 	for(;tmp!=NULL;cnt++){
	// 		tmp = tmp->next;
	// 	}
	// // } else if ( tmp != tail) {
	// // 	cnt = 1;
	// }
	// return cnt;
	int cnt;
	for(cnt = 0; head!=NULL; head=head->next, cnt++){}
	return cnt;
}


// execution sequence double linked list, stores timestamp and action.
typedef struct executionSequence {
	struct executionSequence* next;
	struct executionSequence* prev;
	time_t time_to_go;
	char* execution;
} exe_seq;
int count_execution(exe_seq* head, exe_seq* tail) {
	int cnt;
	for(cnt = 0; head != NULL; head = head->next, cnt++){}
	return cnt;
}
void append_execution();
void pop_execution();



int main() {
	// initialize network


	list* HEAD = (list*)malloc(sizeof(list));
	clients* client_head = NULL;
	clients* last_one = NULL;

	message_queue* msg_q_head = NULL;
	message_queue* msg_q_tail = NULL;

	Tube* tube_head = NULL;
	Tube* tube_tail = NULL;

	int conn_s;
	short int port = PORT;
	char* str_address = "127.0.0.1";


	int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);
	if(listening_socket < 0) {
		printf("fail to alloc socket\n");
		exit(0);
	}

	if( bind(listening_socket, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
		printf("fail to bind\n");
		close(listening_socket);
		exit(0);
	}

	if(listen(listening_socket, 1) < 0) {
		printf("fail to listen %i\n", errno);
		close(listening_socket);
		exit(0);
	}

	int num_of_clients;
	int max_fd = 0;

	fd_set read_fd;
	fd_set write_fd;
	fd_set except_fd;

	// FD_SET(listening_socket, &read_fd);
	// printf("add listening_socket to read_FD set\n");
	// clients* itr;
	// for(itr = client_head; itr != NULL && itr != last_one; itr = itr->next) {
	// 	printf("arm client fd %i\n", itr->socket);
	// 	FD_SET(itr->socket, &read_fd);
	// }
	int retval;
	for(;;) {
		printf("looping\n");
		//reset resources
		FD_ZERO(&read_fd);
		FD_ZERO(&write_fd);
		FD_ZERO(&except_fd);
		max_fd = 0;
		// read in from socket
		FD_SET(listening_socket, &read_fd);
		if(max_fd < listening_socket){ 
			max_fd = listening_socket;
		}
		clients* itr;
		for(itr = client_head; itr != NULL; itr = itr->next) {
			printf("put client fd %i into FD_SET\n", itr->socket);
			FD_SET(itr->socket, &read_fd);
			if(max_fd < itr->socket){max_fd = itr->socket;}
		}

		num_of_clients = count_clients(client_head, last_one);
		printf("now we have %i clients, and max fd is %i\n", num_of_clients, max_fd);


		retval = select(2 + max_fd, &read_fd, NULL, NULL, NULL);

		if(retval == -1) {
			printf("error select\n");
		} else if(retval) {
			// something happened among these read fds.
			if(FD_ISSET(listening_socket, &read_fd)){
				//handle new comming client
				printf("data in from listening socket\n");
				conn_s = accept(listening_socket, NULL, NULL);
				if(conn_s < 0) {
					printf("fail to accept\n");
					continue;
				}
				printf("client %i accepted\n", conn_s);
				add_new_client(conn_s, &client_head, &last_one);
			} else {
				// handle incomming messages
				printf("some clients transfered message\n");
				clients* itr;
				for(itr = client_head; itr != NULL; itr = itr->next) {
					if(FD_ISSET(itr->socket, &read_fd)) {
						printf("client %i got a word\n", itr->socket);
						char* msg_body = (char*)malloc(MAX_MSG_BODY*sizeof(char));
						int ret = read_incoming_msg(itr->socket, msg_body, MAX_MSG_BODY);
						if(ret < 0) {
							printf("fail to recv from client %i, closing connection\n", itr->socket);
							close(itr->socket);
							FD_CLR(itr->socket, &read_fd);
							remove_client(itr->socket, &client_head, &last_one);
							continue;
						}
						add_message(msg_body, ret, itr->socket, &msg_q_head, &msg_q_tail);
					}
				}
			}
		}
		// parse message
		message_queue* msg_itr;
		for(msg_itr = msg_q_head; msg_itr != NULL; msg_itr = msg_itr->next) {
			printf("iterating FD %i's msg: %s\n", msg_itr->fd, msg_itr->content);
			printf("string length is %i\n", strlen(msg_itr->content));
		}
		message_queue* msg_to_parse = dequeue_message(&msg_q_head, &msg_q_tail);
		if(msg_to_parse != NULL) {
			parse_msg(msg_to_parse, tube_head, tube_tail);
		}
		// invoke callBacks
		cb myCB;
		myCB.haha = soso;
		char* mypara = "hw";
		myCB.haha(mypara);
		// send back message to socket

		// check out timer callbacks
		// reset fd sets

	}
}