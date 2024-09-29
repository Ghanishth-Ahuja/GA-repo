#include<stdio.h>
#include<stdlib.h>
#define SIZE 5  //no of elements the stack would have
typedef struct stackstruct
{
    int ele[SIZE];
    int top;
}stack; //creating an alias for the structure stackstruct

// we are passing the address of the structure to the below give functions because we want to 
//make changes to the original stack.
void push(stack*,int);
int pop(stack*);
int isfull(int);
int isempty(int);
int peek(stack*);
void setValueOfTopForStack(stack *);
void traverse(stack*);
int main()
{
    stack s;
    // initialising the value of top to -1
    setValueOfTopForStack(&s);
    int expression,ele,poppedValue,peekValue;
    //Infinite loop until the user presses 5 to terminate the program
    while (1)
    {   

        printf("\npress 1 to push\n");
        printf("press 2 to pop\n");
        printf("press 3 to peek\n");
        printf("press 4 to show the stack\n");
        printf("press 5 to terminate\n");
        printf("Enter the choice");
        scanf("%d",&expression);
        switch (expression)
        {
        case 1: printf("\nEnter the element");
                scanf("%d",&ele);
                push(&s,ele);
                break;
        case 2: poppedValue=pop(&s);
                // if the stack would be empty it'd return -1
                if (poppedValue == -1)
                {
                    printf("Error: Attempted to pop from an empty stack.\n");
                }
                else
                {
                    printf("The value popped is %d",poppedValue);
                    break;
                }
                break;
                
        case 3: peekValue=peek(&s);
                // if the stack would be empty it'd return -1
                if (peekValue == -1)
                {
                    printf("Error: Attempted to peek from an empty stack.\n");
                }
                else
                {
                    printf("The value at peek  is %d",peekValue);
                    break;
                }
                break;
        case 4: traverse(&s);
                break;
        case 5:exit(0);
        default: printf("Invalid entry");
                    break;

        }
    }
    
    return 0;
}
int isfull(int top)
{   
    // if the value of top is equal to size-1 i.e. 4, it means that the last index of the stack
    //also contains a value denoting that the stack is full.
    return top==SIZE-1;
}
int isempty(int top)
{
    // if the value of top is -1 it means it doesn't contains any value, i.e. it's empty
    return top==-1;
}
void push(stack *s,int ele)
{
    if(isfull(s->top))
    {
        printf("Stack overflow");
        return;
    }
    // had we not used structure, it'd have looked like :
    // s.ele[++top]=ele;
    s->ele[++(s->top)]=ele;
}
int pop(stack *s)
{
    if(isempty(s->top))
    {
        return -1;

    }
    return s->ele[(s->top)--];// we decrement the value of top after returning it that's why postfix
}
int peek(stack *s)
{
    if(isempty(s->top))
    {
        return -1;
    }
    //unlike pop we aren't decrementing the value of top.
    return s->ele[s->top];
}
void traverse(stack *s)
{
        if(isempty(s->top))
    {
        printf("Stack Empty");
        return;

    }
    for(int i=0;i<=s->top;i++)
    {
        printf("%d\n",s->ele[i]);
    }
}
void setValueOfTopForStack(stack *s)
{
    s->top=-1;
}