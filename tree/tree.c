#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

main(void)
{
	NodePtr root;
	char *a[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k22","l1"};
	char *shortOne = "1234567890123";
	int k;
	for (k=0;k<2;k++){
		printf("%s", a[k]);
	}
	char *p_hello = "hello";
	char *p_world = "world";
	char *p_treeStr = "tree!";
	char *p_leftleft = "grand1";
	char *p_leftright = "grand2";
	char *p_rightleft = "grand3";
	char *p_rightright = "grand4";
	//build root
	root = (NodePtr)malloc(sizeof(Node));
	root->data = (char*)malloc(cal_length(p_hello)*sizeof(char));
	memcpy(root->data, p_hello, cal_length(p_hello));
	//build left child
	NodePtr tmp;
	tmp = (NodePtr)malloc(sizeof(Node));
	tmp->data = (char*)malloc(cal_length(p_world)*sizeof(char));
	memcpy(tmp->data, p_world, cal_length(p_world));

	root->left = tmp;
	//build right child
	tmp = (NodePtr)malloc(sizeof(Node));
	tmp->data = (char*)malloc(cal_length(p_treeStr)*sizeof(char));
	memcpy(tmp->data, p_treeStr, cal_length(p_treeStr));

	root->right	= tmp;

	//build left child's left child
	tmp = (NodePtr)malloc(sizeof(Node));
	tmp->data = (char*)malloc(cal_length(p_leftleft)*sizeof(char));
	memcpy(tmp->data, p_leftleft, cal_length(p_leftleft));
	root->left->left = tmp;
	//build left child's right child
	tmp = (NodePtr)malloc(sizeof(Node));
	tmp->data = (char*)malloc(cal_length(p_leftright)*sizeof(char));
	memcpy(tmp->data, p_leftright, cal_length(p_leftright));
	root->left->right = tmp;
	//build right child's left child
	tmp = (NodePtr)malloc(sizeof(Node));
	tmp->data = (char*)malloc(cal_length(p_rightleft)*sizeof(char));
	memcpy(tmp->data, p_rightleft, cal_length(p_rightleft));
	root->right->left = tmp;
	//build right child's right child
	tmp = (NodePtr)malloc(sizeof(Node));
	tmp->data = (char*)malloc(cal_length(p_rightright)*sizeof(char));
	memcpy(tmp->data, p_rightright, cal_length(p_rightright));
	root->right->right = tmp;

	printf("@root:%s\n", root->data);
	// printf("%d\n", cal_length(p_hello));
	printf("@leftchild: %s\n", root->left->data);
	printf("@rightchild: %s\n", root->right->data);
	printf("@left left: %s\n", root->left->left->data);
	printf("@left right: %s\n", root->left->right->data);
	printf("@right left: %s\n", root->right->left->data);
	printf("@right right: %s\n", root->right->right->data);

	// for(tmp=head; tmp != NULL;tmp=tmp->next)
	// {
	// 	printf("%s\n", tmp->data);
	// }
}

int cal_length(char *p_char)
{
	int l;
	for(l=0; *p_char++ != '\0';l++){}
	return l;
}

// void append(NodePtr *tail, NodePtr pNewNode)
// {
// 	(*tail)->next = pNewNode;
// 	*tail = pNewNode;
// }