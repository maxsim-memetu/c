#include "apue.h"
#include <pthread.h>

void *
thr_fn1(void *arg)
{
	pthread_t tid;
	tid = pthread_self();
	unsigned u_tid = (unsigned)tid;
	printf("entering thrd%u\n", u_tid);
	// for(int i=0;i<10;i++){
	// 	printf("thread %u couting %d\n", u_tid, i);
	// 	sleep(1);
	// }
	int i=0;
	while(1){
		printf("thread %u counting %d\n", u_tid, i++);
	}
	printf("thrd %u exiting\n", u_tid);
	return ((void *)1);
}
void *
thr_fn2(void *arg)
{
	printf("thread 2 exiting\n");
	pthread_exit((void *)2);
}


int main(void)
{
	printf("in main\n");
	int err;
	int a_tid[10];
	void *tret;
	// int i=0;
	// int *p = a_tid;
	// for(; i<3; i++, p++){
	// 	printf("%d", *p);
	// 	*p = 4;
	// 	printf(":%d\n", *p);
	// }
	for(int i=0; i < 1000; i++)
	{
		// printf("creating thrd%d", i);
		err = pthread_create(&a_tid[i], NULL, thr_fn1, NULL);
		if(err != 0){
			printf("no thrd %d", i);
			continue;
		}
	}
	// err = pthread_create(&a_tid[0], NULL, thr_fn1, NULL);
	// if(err != 0){
	// 	printf("no th1");
	// 	exit(1);
	// }
	// err = pthread_create(&a_tid[1], NULL, thr_fn2, NULL);
	// if(err != 0){
	// 	printf("no th2");
	// 	exit(1);
	// }
	sleep(5);
	printf("main exiting\n");
	exit(0);


}
