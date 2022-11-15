#include <iostream>
#include <malloc.h>
#define maxsize 100
using namespace std;

typedef struct LNode{
    int data;
    LNode *next;
}LNode,*linklist;

int delete_list(int x,int y,linklist p)
{
    while(p)
    {
        int num;
        num=p->next->data;
        if((num>=x)&&(num<=y)&&(p->next))
        {
            linklist q=p->next;
            p->next=q->next;
            delete(q);
        }
        p=p->next;
    }
    return 1;
}
int print_list(linklist head)
{
    while(head)
    {
        head=head->next;
        cout<<head->data<<" ";
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    linklist L,r;
    L=new LNode();
    L->next=NULL;
    r=L;
    for(int i=0;i<n;i++)
    {
        linklist p;
        p=new LNode();
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
    int x,y;
    cin>>x>>y;
    delete_list(x,y,L);
    print_list(L);
    return 0;
}