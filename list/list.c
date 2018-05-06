#include <stdio.h>
#include <stdlib.h>
#include "list.h"

main(void)
{
	NodePtr head;
	char *a[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k22","l1"};
	char *shortOne = "1234567890123";
	int k;
	for (k=0;k<2;k++){
		printf("%s", a[k]);
	}
	char *p_hello = "hello";
	head = (NodePtr)malloc(sizeof(Node));
	head->data = (char*)malloc(cal_length(p_hello)*sizeof(char));
	memcpy(head->data, p_hello, cal_length(p_hello));
	printf("%s\n", head->data);
	printf("%d\n", cal_length(p_hello));
	NodePtr tail = head;
	int cnt;
	printf("test append\n");
	NodePtr tmp;
	tmp = (NodePtr)malloc(sizeof(Node));
	tmp->data = "world";
	append(&tail, tmp);
	tmp = head;
	printf("1st:%s\n", tmp->data);
	tmp = tmp->next;
	printf("2nd:%s\n", tmp->data);
	printf("sizeof a[10] = %d", cal_length(a[10]));
	for (cnt=10;cnt>0;cnt--)
	{
		tmp = (NodePtr)malloc(sizeof(Node));
		// memcpy(tmp->data, shortOne+cnt, 2);
		tmp->data = shortOne+cnt;
		printf("copying %s\n", tmp->data);
		tmp->next = NULL;
		append(&tail, tmp);
	}

	for(tmp=head; tmp != NULL;tmp=tmp->next)
	{
		printf("%s\n", tmp->data);
	}
	// char *p_hello = "hello";
	// char *p_world = " world";
	// head = malloc(sizeof(list)/sizeof(int));
	// head.data = malloc(6*sizeof(char));
	// list node1;
	// node1 = malloc(sizeof(list)/sizeof(int));
	// head.next = node1;
	// node1.data = malloc(7*sizeof(char));

	// memcpy(head.data, p_hello);
	// memcpy(node1.data, p_world);

	// int i;
	// list* p=&head;
	// for (i=0;i<2;i++)
	// {
	// 	printf("%s",p->data);
	// 	p=p->next;
	// }
}

int cal_length(char *p_char)
{
	int l;
	for(l=0; *p_char++ != '\0';l++){}
	return l;
}

void append(NodePtr *tail, NodePtr pNewNode)
{
	(*tail)->next = pNewNode;
	*tail = pNewNode;
}