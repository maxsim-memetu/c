#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

struct foo
{
	int f_count;
	pthread_mutex_t f_lock;
};

struct foo *
foo_alloc(void)
{
	struct foo *fp;
	if((fp = malloc(sizeof(struct foo))) != NULL){
		fp->f_count = 1;
		if(pthread_mutex_init(&fp->f_lock, NULL) != 0){
			free(fp);
			return(NULL);
		}
	}
	return(fp);
};

void
foo_hold(struct foo *fp, unsigned thrd_id)
{
	pthread_mutex_lock(&fp->f_lock);
	printf("%u holding count:%d", thrd_id, &fp->f_count++);
	pthread_mutex_unlock(&fp->f_lock);
}

void
foo_rele(struct foo *fp)
{
	pthread_mutext_lock(&fp->f_lock);
	if (--fp->f_count == 0) {
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_destroy(&fp->f_lock);
		free(fp);
	} else {
		pthread_mutex_unlock(&fp->f_lock);
	}
}

void *
thr_fn(void *arg)
{
	pthread_t tid;
	tid = pthread_self();
	unsigned u_tid = (unsigned)tid;
	foo_hold()
}