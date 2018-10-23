#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *l;
        struct node *r;
	int data;       
}NODE;

int size(NODE* root)
{
	if(root == NULL)
		return 0;
	else
		return(size(root->l) + 1+size(root->r));
}
int min(NODE* root)
{
	NODE*tmp=root;
	if(tmp==NULL)
		return 0;
	else
	{
		while(tmp->l != NULL)
			tmp=tmp->l;
	}
	return tmp->data;
}
int findlev(NODE*root,int num,int lev)
{
	
	if(root==NULL)
		return -1;
	else
	{
		if(root->data == num)
			return lev;
		//int l=findlev(root->l,num,lev+1);
		//return (l!=-1)?l:findlev(root->r,num,lev+1);
		if(num<root->data)
			return findlev(root->l,num,lev+1);
		else
			return findlev(root->r,num,lev+1);

	}
}
NODE* findlca(NODE *root, int r1, int r2)
{
	if(root==NULL)
		return NULL;
	else
	{
		if(root->data == r1 || root->data == r2)
			return root;
		NODE *left = findlca(root->l,r1,r2);
		NODE *right = findlca(root->r,r1,r2);
		if(left != NULL && right != NULL)
			return root;
		if(left != NULL)
			return left;
		if(right!=NULL)
			return right;
	}
}
NODE * findlcabst(NODE *root, int r1,int r2)
{
	if(root==NULL)
		return NULL;
	else
	{
		if(r1<root->data && r2<root->data)
			return findlcabst(root->l,r1,r2);
		if(r1>root->data && r2>root->data)
			return findlcabst(root->r,r1,r2);
		else
			return root;
	}
}
int maxdistance(NODE *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int ldist = maxdistance(root->l);
		int rdist = maxdistance(root->r);
		if(ldist>rdist)
			return ldist+1;
		else
			return rdist+1;
	}
}
NODE* createnode(int num)
{
	NODE *tmp = (NODE*)malloc(sizeof(NODE));
	tmp->data=num;
	tmp->l=NULL;
	tmp->r=NULL;
	return tmp;

}
void insert(NODE **root, int num)
{
	if(*root==NULL)
		*root=createnode(num);
	else
	{
		if((num>(*root)->data) && ((*root)->r == NULL))
			(*root)->r=createnode(num);
		else if((num>(*root)->data) &&((*root)->r != NULL))
			insert(&(*root)->r,num);
		else if((num<(*root)->data)&& ((*root)->l == NULL))
			(*root)->l=createnode(num);
		else if((num<(*root)->data)&&((*root)->l !=NULL))
			insert(&(*root)->l,num);
	}
}

void inorder(NODE * root)
{
	if(root == NULL)
	{
		return ;
	}
	else
	{
		inorder(root->l);
		printf("%d\n",root->data);
		inorder(root->r);
	}
}
int finddistance(NODE *root, int r1,int r2)
{
	int path1 = findlev(root,r1,0);
	int path2 = findlev(root,r2,0);
	//NODE * lca = findlca(root,r1,r2);
	NODE * lca = findlcabst(root,r1,r2);
	if(lca == NULL)
		return -1;
	int path3 = findlev(root,lca->data,0);
	return (path1 + path2 - 2*path3);
}
int main()
{
	NODE *root=NULL;
	insert(&root,3);
	insert(&root,2);
	insert(&root,1);
	insert(&root,4);
	insert(&root,7);
	insert(&root,6);
	insert(&root,8);
	insert(&root,0);
	insert(&root,-1);
	insert(&root,-2);
//	insert(&root,5);
	inorder(root);
	printf("size id %d\n",size(root));
	printf("maxdist is %d\n",maxdistance(root)-1);
	printf("min is %d\n",min(root));
	printf("lev is %d\n",findlev(root,3,0));
	NODE* lca = findlca(root,6,8);
	printf("LCA is %d\n",lca->data);
	//Distance Printing
	printf("Distance %d\n",finddistance(root,6,8));
	
}
