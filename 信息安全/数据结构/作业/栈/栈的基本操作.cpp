#include <iostream>
#define size 1000
#define OK 1
#define OVERFLOW -1
using namespace std;

struct queue
{
    int number[size];
    int rear;
    int front;
};

void init_queue(queue *A)
{
    A->rear=-1;
    A->front=-1;
}

int enqueue(queue *q,int n)
{
    q->rear++;
    if(q->rear>size)
        exit(OVERFLOW);
    q->number[q->rear]=n;
    return OK;
}

int popqueue(queue *q,queue *p,bool canshu)
{
    if(q->rear==q->front)
            return 0;
    if(canshu)
    {
        q->front++;
        enqueue(p,q->number[q->front]);
        if(q->rear==q->front)
            return 0;

    }
    else
    {
        q->front++;
        enqueue(p,q->number[q->front]);
        if(q->rear==q->front)
            return 0;
        q->front++;
        enqueue(p,q->number[q->front]);
        if(q->rear==q->front)
            return 0;
    }
    
    return OK;
}
void print_queue(queue *q)
{
    while(q->rear-1>q->front)
    {
        q->front++;
        cout<<q->number[q->front]<<" ";
    }
    cout<<q->number[q->rear];
}
int main()
{
    queue *A,*B,*C;
    A=new queue;
    B=new queue;
    C=new queue;
    init_queue(A);
    init_queue(B);
    init_queue(C);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int n;
        cin>>n;
        if(n%2==0)
            enqueue(B,n);
        else
            enqueue(A,n);
    }
    int flag=0;
    while(flag!=2)
    {
        flag=0;
        if(!popqueue(A,C,false))
            flag++;
        if(!popqueue(B,C,true))
            flag++;
    }
    
    print_queue(C);
    return 0;
}