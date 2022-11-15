#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prior;
};

//建立链表
void Create(node *head)
{

    node *tail=head;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        
        node *s=new node;
        s->next=NULL;
        s->prior=NULL;
        cin>>s->data;
        tail->next=s;
        s->prior=tail;
        tail=tail->next;//移动到下一个结点
    }
}

//删除指定结点
void Delete(node *head)
{
    int min,max;
    cin>>min>>max;
    node *p;
    p=head->next;
    while(p)
    {
        int e=p->data;
        
        if((e>=min)&&(e<=max))
        {  
            node *t=p->prior;
            node *q=p;
            p->prior->next=p->next;
            p->next->prior=p->prior;
            delete(q);
            p=t->next;
        }
        else
            p=p->next;
        
    }
}
void Show(node *head)
{
    node *p=head->next;
    while(p->next)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<p->data;//以前写的是cout<<p->next->data
    cout<<endl; 
}
int main()
{
    node *head=new node;
    head->next=NULL;//相当于*head.next
    head->prior=NULL;
    Create(head);//地址传过去指针接收
    Delete(head);
    Show(head);
    return 0;
}