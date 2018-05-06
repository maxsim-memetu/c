#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

NodePtr find(int x, NodePtr T)
{
	if(T == NULL)
	{
		return NULL;
	} else {
		if(x == T->data)
		{
			return T;
		}
		else if(x > T->data)
		{
			return find(x, T->left);
		}
		else
		{
			return find(x, T->right);
		}
	}
}

NodePtr find_max(NodePtr T){
	if(T == NULL)
	{
		return T;
	} else {
		if(T->right != NULL)
		{
			find_max(T->right)
		} else {
			return T;
		}
	}
}

void insert(int x, NodePtr T)
{
	if(T == NULL){
		T = (NodePtr)malloc(sizeof(Node));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
	} else {
		if(T->data >= x)// if x is already in the tree we do nothing ,so here should be 
		{
			insert(x, T->left);
		} else {
			insert(x, T->right);
		}
	}
}



NodePtr delete(int x, NodePtr T)
{
	if(T == NULL){
		return T;
	}
	if(x < T->data)
	{
		T->left = delete(x, T->left);
		return T;
	} else if(x > T->data){
		T->right = delete(x, T->right);
		return T;
	} else {
		if((T->left != NULL) && (T->right != NULL))
		{
			NodePtr temp = find_max(T->left);
			temp->left = T->left;
			temp->right = T->right;
			free(T);
			return temp;
		} else if(T->left != NULL)
		{
			NodePtr temp = T->left;
			free(T);
			return temp;
		} else if(T->right != NULL)
		{
			NodePtr temp = T->right;
			free(T);
			return temp;
		} else {
			free(T);
			return NULL;
		}
	}

}