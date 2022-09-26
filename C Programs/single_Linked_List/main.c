#include<stdio.h>
#include<stdlib.h>
void Create_LL();
void Print_LL();
void reverse_LL();
void Add_First_Node();
void Add_Last_Node();
void Add_Any_Node();
void delete_first_node();
void delete_end_node();
void delete_any_node();
void delete_List();
void sort_LL();
void size();
struct node
{
    int data;
    struct node *next;
}*head;
int main()
{
    int n;
    printf("Enter size of LL:");
    scanf("%d",&n);
    printf("Enter elements of Linked List:");
    for(int i=0;i<n;i++)
    {
        Create_LL();
    }
    //Add_First_Node();
    //Add_Last_Node();
    //Add_Any_Node();
    //delete_first_node();
    //delete_end_node();
    //delete_any_node();
    //sort_LL();
    reverse_LL();
    size();
    Print_LL();
    //delete_List();
    //Print_LL();
    return 0;
}
void Create_LL()
{
    int num;
    struct node *new_node,*ptr;
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    if(head==NULL)
    {
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new_node;
        new_node->next=NULL;
    }
}
void Print_LL()
{
    struct node *temp;
    temp=head;
    while(head!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    if(head==NULL)
    {
        printf("Linked List is empty");
    }
}
void reverse_LL()
{
    struct node *current,*prev=NULL,*next=NULL;
    current=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
void Add_First_Node()
{
    struct node *new_node;
    int num;
    printf("Enter first node element:");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=head;
    head=new_node;
}
void Add_Last_Node()
{
    struct node *new_node,*ptr;
    int num;
    printf("Enter last node element:");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=new_node;
    new_node->next=NULL;
}
void Add_Any_Node()
{
    struct node *new_node,*ptr;
    int num,pos;
    printf("Enter data to insert in any node:");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=head;
    printf("Enter position of data to insert a new node:");
    scanf("%d",&pos);
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        if(pos==ptr->data)
            break;
    }
    new_node->next=ptr->next;
    ptr->next=new_node;
}
void delete_first_node()
{
    head=head->next;
}
void delete_end_node()
{
    struct node *ptr,*prev;
    ptr=head;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=NULL;
}
void delete_any_node()
{
    struct node *ptr,*prev;
    ptr=head;
    int val;
    printf("Enter data of node to delete:");
    scanf("%d",&val);
    prev=ptr;
    while(ptr->data!=val)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=ptr->next;
}
void delete_List()
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        head=ptr->next;
        ptr=head;
    }
}
void sort_LL()
{
    struct node *ptr1,*ptr2;
    int temp;
    ptr1=head;
    while(ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->data>ptr2->data)
            {
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}
void size()
{
    struct node *ptr;
    int count=0;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    printf("size of Linked List is:%d\n",count);
}
