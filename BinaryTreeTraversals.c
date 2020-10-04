#include<stdio.h>
#include<stdlib.h>

struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
};
struct Tree* create();
void preorder(struct Tree*);
int main()
{
	struct Tree *Root;
	Root=create();
	preorder(Root);
}
struct Tree *create()
{
	int x;
	scanf("%d",&x);
	if(x==-1)
	return NULL;
	else
	{
		struct Tree *temp;
		temp=(struct Tree*)malloc(sizeof(struct Tree));
		temp->data=x;
		printf("Enter left child of %d",x);
		temp->left=create();
		printf("Enter Right child of %d",x);
		temp->right=create();
		return temp;
		
	}
}

void preorder(struct Tree *Root)
{
	if(Root!=NULL)
	{
		printf("%d ",Root->data);
		preorder(Root->left);
		preorder(Root->right);
	}
}

void inorder(struct Tree *Root)
{
	if(Root!=NULL)
	{
		preorder(Root->left);
    printf("%d ",Root->data);
		preorder(Root->right);
	}
}

void postorder(struct Tree *Root)
{
	if(Root!=NULL)
	{
		preorder(Root->left);
		preorder(Root->right);
		printf("%d ",Root->data);
	}
}