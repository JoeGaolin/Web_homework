#include <iostream>
#include <stdio.h>
#define OK 1
#define ERROR 0
#define maxsize 100
using namespace std;
//打表；
char symbol[7]="+-*/()";
int priority[5][5]={0};

struct stack
{
    char data[maxsize];
    int rear;
    int front;
};

void init_stack(stack *s)
{
    s->rear=-1;
    s->front=-1;
}
//进栈
int enstack(stack *s,char ch)
{
    if(s->rear-s->front==maxsize)
        return ERROR;
    s->rear++;
    s->data[s->rear]=ch;
    return OK;
}
//出栈
char outstack(stack *s)
{
    char ch=s->data[s->rear];
    s->rear--;
    return ch;
}
//比较优先级
int judge(char push,char top)
{
    int col,row;
    for(int i=0;i<5;i++)
    {
        if(push==symbol[i])
            col=i;
        if(top==symbol[i])
            row=i;
    }
    if(priority[row][col])
        return OK;//可以压进去
    else return ERROR;
}

void printstack(stack *s)
{
    while(s->rear-1!=s->front)
    {
        s->front++;
        if(s->data[s->front]>='0'&&s->data[s->front]<='9')
            cout<<(s->data[s->front]-'0')<<" ";
        else
            cout<<s->data[s->front]<<" ";
    }
    cout<<s->data[s->rear];

}
int fenxi(char *str,stack *s1,stack *s2)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            enstack(s1,str[i]);
        }
        else
        {
            if(s2->rear==-1)
                enstack(s2,str[i]);
            else if(str[i]==')')
            {
                while(s2->data[s2->rear]!='(')
                {
                    enstack(s1,outstack(s2));
                }
                outstack(s2);//弹出(;
            }
            else if(judge(str[i],s2->data[s2->rear]))//可以放进去
            {
                enstack(s2,str[i]);
            }
            else //如果不能压进去那就得出栈
            {
                while(judge(str[i],s2->data[s2->rear])==ERROR)
                {
                    enstack(s1,outstack(s2));//弹出s2栈顶元素,压入s1;
                    if(s2->rear==-1)
                        break;
                }
                enstack(s2,str[i]);
            }
            
        }
    }
    while(s2->rear!=-1)
        enstack(s1,outstack(s2));
    printstack(s1);
    return OK;
}
int main()
{
    priority[0][2]=1;priority[0][3]=1;priority[1][2]=1;priority[1][3]=1;
    for(int i=0;i<=4;i++)
    {
        priority[4][i]=1;
        priority[i][4]=1;
    }
    stack *s1,*s2;
    s1=new stack;
    s2=new stack;
    init_stack(s1);
    init_stack(s2);
    char str[1000];
    scanf("%s",str);
    fenxi(str,s1,s2);
    return 0;

}