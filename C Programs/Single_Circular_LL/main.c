#include <stdio.h>
#include <stdlib.h>
void Create_LL();
void Print_LL();
void reverse_LL();
struct node
{
    int data;
    struct node *next;
}*head;
int main()
{
    int n;
    printf("enter size of Circular Linked List:");
    scanf("%d",&n);
    printf("Enter elements of Circular Linked List:");
    for(int i=0;i<n;i++)
    {
        Create_LL();
    }
    reverse_LL();
    Print_LL();
    return 0;
}
void Create_LL()
{
    struct node *new_node,*ptr;
    int num;
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    if(head==NULL)
    {
        new_node->next=new_node;
        head=new_node;
    }
    else
    {
        ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
        ptr->next=new_node;
        new_node->next=head;
    }
}
void Print_LL()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
        printf("Circular Linked List is empty");
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
void reverse_LL()
{
    struct node *current,*next=NULL,*prev=NULL;
    current=head;
    do
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }while(current!=head);
    head->next=prev;
    head=prev;
}
