#define LIST_H
typedef struct list {
	char * data;
	struct list* next;
} Node;
typedef struct list *NodePtr;