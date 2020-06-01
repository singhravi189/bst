#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE *newNode(int num)
{
	NODE * tmp= (NODE*)malloc(sizeof(NODE));
	tmp->data=num;
	tmp->left=tmp->right=NULL;
	return tmp;
}

NODE* insert(NODE* node, int num)
{
	if(node==NULL)
		return newNode(num);
	else
	{
	if(num>node->data)
		node->right=insert(node->right,num);
	else
		node->left=insert(node->left,num);
	} 
return node;
}
int identical(NODE *x, NODE*y)
{
	NODE* tmp;
	if(x==NULL && y==NULL)
		return TRUE;
	if(x==NULL && y!=NULL)
		return FALSE;
	if(x!=NULL && y==NULL)
		return FALSE;
	else
	{
		if((x->data == y->data) && (identical(x->left,y->left))&&(identical(x->right,y->right)))
			return TRUE;
		else
			return FALSE;
	}
}
void Mirror(NODE* node)
{
	NODE *tmp;
	if(node==NULL)
		return;
	else
	{
		Mirror(node->left);
		Mirror(node->right);
		tmp=node->left;
		node->left=node->right;
		node->right=tmp;
	}
}
void inorder(NODE* node)
{
	if(node!=NULL)
	{
		inorder(node->left);
		printf("%d\n",node->data);
		inorder(node->right);
	}
}
int Search(NODE* node,int num)
{
	if(node==NULL)
		return -1;
	NODE * cur=node;
	while(cur!=NULL || cur->data != num)
	{
		if(num > cur->data)
			cur=cur->right;
		else
			cur=cur->left;
	}
	if(cur==NULL)
	{
		printf("Not Found \n");
		return -1;
	}
	else
	{
		printf("Found\n");
		return 0;
	}
}
int main()
{
	//Create BST X and y
	//Insert Elements
	NODE *x=NULL;
	x=insert(x,1);
	insert(x,2);
	insert(x,3);
	insert(x,4);
	insert(x,5);
	insert(x,6);

	NODE *y=NULL;
	y=insert(y,1);
	insert(y,2);
	insert(y,3);
	insert(y,4);
	insert(y,5);
	insert(y,7);

	//Traversal
	inorder(x);
	//Check for identical
	if(identical(x,y)==TRUE)
		printf("Same\n");
	else
		printf("Different\n");
	//Search Element
	/*
	if(!Search(x,7))
		printf("Found\n");
	else
		printf("Not Found \n");*/
	//Delete a Particular element
	//Find LCA
	//Mirror
	Mirror(x);
	inorder(x);
	return 0;
}
