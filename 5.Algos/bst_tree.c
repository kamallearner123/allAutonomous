#include <stdio.h>
#include <stdlib.h>

#define bal_ht(a,b) (a-b)*(a-b)

typedef struct node {
	int data, ht;
	struct node *left, *right;
} Node;


Node *root = NULL;

void inorder (Node *root) 
{
	if (root== NULL) 
		return;
	inorder(root->left);
	printf("Data = %d\n", root->data);
	inorder(root->right);
	return;
}

void postorder (Node *root) 
{
	if (root== NULL) 
		return;
	inorder(root->left);
	inorder(root->right);
	printf("Data = %d\n", root->data);
	return;
}
void preorder (Node *root) 
{
	if (root== NULL) 
		return;
	printf("Data = %d\n", root->data);
	inorder(root->left);
	inorder(root->right);
	return;
}


void insert(int data, Node **root) 
{
	Node *new;
	new = calloc(1, sizeof(Node));
	new->data = data;
	if (*root == NULL)
	{
		*root = new;
		return;
	}
	
	if (data > (*root)->data)
	{
		printf("Got to right to %d\n", (*root)->data);
		insert(data, &(*root)->right);
	}
	else 
	{
		printf("Got to left to %d\n", (*root)->data);
		insert(data, &(*root)->left);
	}
}

Node **find(Node **iroot, int data)
{
    Node **root = iroot;
	if (*root == NULL)
		return root;

    while(*root!=NULL) {
	    if ((*root)->data == data) 
	        return root;
	    if (data > (*root)->data)
		    root = &((*root)->right);
	    else
		    root = &((*root)->left);
    }

    return root;
}

void delete() 
{
	Node **loc, *del_node, *tmp;
	int data;

	printf("Enter the number to delete:");
	scanf("%d", &data);
	loc = find(&root, data);

	if (*loc == NULL) {
		printf("Not data found\n");
        return;
    }
	else {
		printf("Data found at : %p\n", *loc);
    }

	del_node = *loc;

	*loc = del_node->right;
	tmp = del_node->right;

	if (tmp == NULL) {
		*loc = del_node->left;
		return;
	}

	while(tmp->left != NULL)
		tmp = tmp->left;
	tmp->left = del_node->left;

	free(del_node);

	return;
}


int main()
{
	int data, i=10;
	for (;i>0;i--)
	{
		printf("Enter the number:");
		scanf("%d", &data);
		insert(data, &root);
	}

	printf("Pre order\n");
	preorder(root);
	printf("Post order\n");
	postorder(root);
	printf("in order\n");
	inorder(root);

	for(i=0;i<10;i++)
	{
		delete();
		inorder(root);
	}
}


