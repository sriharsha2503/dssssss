#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int *st;
    int tos1,tos2,n;
}stack;
int checkoverflow(stack *s){
    if (s->tos2==(s->tos1)+1)
        return 1;
    return 0;
}
void push1(stack *s,int x)
{
    if(checkoverflow(s))
    {
        printf("Overflow!");
        return;
    }
    (s->st)[++(s->tos1)]=x;
}
int pop1(stack *s)
{
    if(s->tos1==-1){
        printf("Underflow!");
        return -5;
    }
    return (s->st)[(s->tos1)--];
}
void push2(stack *s,int x)
{
    if(checkoverflow(s))
    {
        printf("Overflow!");
        return;
    }
    (s->st)[--(s->tos2)]=x;
}
int pop2(stack *s)
{
    if(s->tos2==-1){
        printf("Underflow!");
        return -5;
    }
    return (s->st)[(s->tos1)++];
}
int main()
{
    int n,ch=1,temp;
    stack s;
    printf("max size:");
    scanf("%d",&n);
    s.st=(int *)malloc(n*sizeof(int));
    s.tos1=-1;
    s.tos2=n;
    s.n=n;
    printf("1.Push1 2.Push2 3.Pop1 4.Pop2 5.Exit");
    do{
        printf("\nEnter choice:");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("Element to push:");
            scanf("%d",&temp);
            push1(&s,temp);
        }
        else if(ch==2)
        {
            printf("Element to push:");
            scanf("%d",&temp);
            push2(&s,temp);
        }
        else if(ch==3)
        {
            printf("Number popped:%d",pop1(&s));
        }
        else if(ch==4)
        {
            printf("Number popped:%d",pop2(&s));
        }
        else
            ch=5;
    }while(ch!=5);
}