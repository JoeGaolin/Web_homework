typedef struct line{
    struct line * prior; //指向直接前趋
    int data;
    struct line * next; //指向直接后继
}line;

line* initLine(line * head){
    head=(line*)malloc(sizeof(line));//创建链表第一个结点（首元结点）
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    line * list=head;
    for (int i=2; i<=3; i++) {
        //创建并初始化一个新结点
        line * body=(line*)malloc(sizeof(line));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;
      
        list->next=body;//直接前趋结点的next指针指向新结点
        body->prior=list;//新结点指向直接前趋结点
        list=list->next;
    }
    return head;
}