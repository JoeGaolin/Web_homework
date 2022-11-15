//顺序队列
#define QUEUESIZE 64

typedef struct _sequ
{
    dataType data[QUEUESIZE];
    int front;
    int rear;
}SeQueue,*pSeQueue;
//顺序队列
pSeQueue SeQueueCreat()
{
    pSeQueue p = (pSeQueue)malloc(sizeof(SeQueue));
    if(NULL == p)
    {
        perror("SeQueueCreat malloc");
        return NULL;
    }
    memset(p,0,sizeof(SeQueue));
    p->front = -1;
    p->rear = -1;
    return p;
}
//入队
int SeQueueEnter(pSeQueue Q,dataType data)
{
    Q->rear++;
    if(Q->rear > QUEUESIZE)
        return -1;
    Q->data[Q->rear] = data;
    return 0;
}
//出队
int SeQueueExit(pSeQueue Q,dataType *data)
{
    if(Q->front == Q->rear)
        return -1;
    Q->front++;
    *data = Q->data[Q->front];
    return 0;
}
//释放
int SeQueueFree(pSeQueue Q)
{
    free(Q);
    return 0;
}
//打印队列
int printSeQueue(pSeQueue Q)
{
    int i = 0;
    for(i = Q->front + 1;i <= Q->rear;i++)
    {
        printf("%4d ",Q->data[i]);
    }
    printf("\r\n");
    return i;
}