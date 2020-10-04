#include<stdio.h>
#include<stdlib.h>
struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};
struct BST* create(struct BST *,int);

void inorder(struct BST*);
void preorder(struct BST*);
void postorder(struct BST*);

int main()
{
    int n,data,newdata;
    struct BST *root=NULL;
    printf("Enter no of leaves\n");
    scanf("%d",&n);
    while(n--)
    {
        printf("Enter data\n");
        scanf("%d",&data);
    root=create(root,data);
    }
    printf("Original Bst\n");
    printf("Inorder Traversal\n");
    inorder(root);
    printf("\nPreorder Traversal\n");
    preorder(root);
    printf("\nPostorder Traversal\n");
    postorder(root);
    
    root=insert(root);
    printf("After New Data Insertion\n");
    printf("Inorder Traversal\n");
    inorder(root);
    printf("\nPreorder Traversal\n");
    preorder(root);
    printf("\nPostorder Traversal\n");
    postorder(root);
}
struct BST *create(struct BST *root,int data)
{
    if(root==NULL)
    {
        root=(struct BST*)malloc(sizeof(struct BST));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        if(data<root->data)
        root->left= create(root->left,data);
        else
        if(data>root->data)
        root->right= create(root->right,data);
    }
    return root;
}


void inorder(struct BST * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct BST * root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct BST * root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
