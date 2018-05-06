# include <pthread.h>
# include <stdio.h>
# include <time.h>




void start_fn(){
	pthread_t tid;
	tid = pthread_self();
	printf("in thread %u start function\n", (unsigned int)tid);
	int k=0;
	for(;k<10;k++){
		printf("%u\n", (unsigned int)tid);
		sleep(1);
	}

}

int main(){
	pthread_t* pa = (pthread_t)malloc(sizeof(pthread_t)*100);
	// pthread_attr_t attr;
	// PTHREAD_ATTR_INIT(&attr);
	// pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	// pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	void ** rval;
	int i = 0;
	for(;i<100;i++){
		int rs = pthread_create(pa+i, NULL, start_fn, NULL);
		if(rs == 0){
			printf("a new thread %u is created\n", *(pa+i));
		} else {
			printf("error when create thread\n");
		}
	}
	int j=0;
	for(;j<100;j++){
		pthread_join(*(pa+j), rval);
	}
	printf("exiting main\n");
	return 0;
}