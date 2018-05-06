#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void find_prev(char x, NodePtr L)
{
	NodePtr p = L;
	while((p->next != NULL) && (p->next->data != x))
	{
		p = p->next;
	}
	return p
}
int delete(char x,NodePtr L)
{
	NodePtr p = find_prev(x, L);
	if(p == NULL){
		return 1;
	} else {
		NodePtr temp = p->next;
		p->next = temp->next;
		free(temp);
		return 0;
	}
}

int insert(char x, NodePtr L, NodePtr p)
{
	if(p == NULL){
		return 1;
	} else {
		NodePtr new_node = (NodePtr)malloc(sizeof(Node));
		new_node->data = &x;
		NodePtr temp = p->next;
		if(temp == NULL){
			temp = new_node;
		} else {
			p->next = new_node;
			p->next->next = temp;
		}
		return 0
	}
}