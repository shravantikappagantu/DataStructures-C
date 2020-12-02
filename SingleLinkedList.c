#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*head = NULL;

struct node* create(struct node*head)
{
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&temp->data);
    if (!temp)
        return NULL;
    else
    {
        temp->next = head;
    }
    return(temp);
    free(temp);
}

void display(struct node*head)
{
    if(head==NULL)
    {
        printf("node not created yet");
    }
    else
    {
        while(head!=NULL){
        printf("%d",head->data);
        head=head->next;
        }
    }
}

struct node* insert(struct node*head)
{
    int data, k=1,pos;
    struct node* temp,*p;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter data to be inserted: ");
    scanf("%d",&data);
    temp->data=data;
    
    printf("enter position to be inserted in: ");
    scanf("%d",&pos);
    p=head;
    if(pos == 1)
    {
        temp->next=p;
        head=temp;
    }
    else
    {
        while(p!=NULL && k<pos)
        {
            p=p->next;
            k++;
        }
        temp->next = p->next;
        p->next = temp;
    }
    return head;
}

struct node* del(struct node*head)
{
    struct node* temp, *p,*q;
    temp = (struct node*)malloc(sizeof(struct node));
    int k=1,pos;
    printf("enter position to be deleted");
    scanf("%d",&pos);
    
    p=head;
    if(pos==1)
    {
        head= p->next;
    }
    else
    {
        while(p!=NULL && k<pos)
        {
            k++;
            q=p;
            p=p->next;
        }
        q->next = p->next;
    }
    return head;
}

int main()
{
    int n;
    printf("enter no of nodes: ");
    scanf("%d",&n);
    while(n--)
    {
        head = create(head);
    }
    head=insert(head);
    head=del(head);
    display(head);
    free(head);
}