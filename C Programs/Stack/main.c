#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
}*top=NULL;
struct stack *push(struct stack *top,int val);
struct stack *pop(struct stack *);
void peek();
struct stack *display(struct stack *);
int main()
{
    int val,option;
    do
    {
        printf("Main menu\n");
        printf("1.push\n2.pop\n3.peek\n4.display\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter value to be pushed");
                scanf("%d",&val);
                top=push(top,val);
                break;
            case 2:
                top=pop(top);
                break;
            case 3:
                peek();
                break;
            case 4:
                top=display(top);
                break;
        }
    }while(option<5);

    return 0;
}
struct stack *push(struct stack *top,int val)
{
    struct stack *ptr;
    ptr=(struct stack *)malloc(sizeof(struct stack));
    ptr->data=val;
    if(top==NULL)
    {
        ptr->next=NULL;
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
    return top;
}
struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr=top;
    if(top==NULL)
    {
        printf("stack Underflow\n");
    }
    else
    {
        top=top->next;
        printf("The deleted value is %d\n",ptr->data);
    }
    return top;
}
void peek()
{
    if(top==NULL)
        printf("Stack is empty\n");
    else
        printf("%d\n",top->data);
}
struct stack * display(struct stack *top)
{
    struct stack *ptr;
    ptr=top;
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    return top;
}
