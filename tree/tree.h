#define TREE_H
typedef struct tree {
	char * data;
	struct tree* left;
	struct tree* right;
} Node;
typedef struct tree *NodePtr;