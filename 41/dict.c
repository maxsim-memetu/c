#include <stdio.h>

#define QUO 13

typedef struct List {
	struct List* prev;
	struct List* next;
	char* key;
	char* content;
} list;
typedef struct Dict {
	list* index[QUO];
} dict;
void init(dict* d) {
	int i;
	for(i = 0; i < QUO; i++) {
		printf("nullify the % th element\n", i);
		(d->index)[i] = NULL;
	}
}
void add(dict* d, char* k, char* v) {
	char* itr;
	int cnt = 0;
	for (itr = k; *itr != '\0'; itr++) {
		cnt += (*itr);
	}
	int remain = cnt % QUO;
	list* l = (list*)malloc(sizeof(list));
	l->prev = l->next = NULL;
	// use malloc + memset?
	l->key = k;
	l->content = v;
	if((d->index)[remain] == NULL) {
		//empty slot
		(d->index)[remain] = l;
	} else {
		// at least 1 value
		list* head = (d->index)[remain];
		while(head->next != NULL){
			head=head->next;
		}
		head->next = l;
		l->prev = head;
	}
}

char* get(dict* d, char* k) {
	char* itr;
	int cnt = 0;
	for (itr = k; *itr != '\0'; itr++) {
		cnt += (*itr);
	}
	int remain = cnt % QUO;
	list* head = (d->index)[remain];
	if(head == NULL) {
		printf("no element with key %s\n", k);
		return NULL;
	} else {
		for(; head != NULL; head=head->next) {
			if(head->key == k) {
				return head->content;
				break;
			}
		}
	}
}

int main() {
	dict* k = (dict*)malloc(sizeof(dict));
	init(k);
	add(k, "1", "soso");
	add(k, "2", "foo");
	add(k, "3", "bar");
	printf("1 : %s\n", get(k, "1"));
	printf("2 : %s\n", get(k, "2"));
	printf("3 : %s\n", get(k, "3"));

}
