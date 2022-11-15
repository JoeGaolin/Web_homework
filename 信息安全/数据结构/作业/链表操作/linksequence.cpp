#include <iostream>
#include <malloc.h>
using namespace std;

typedef int Elemtype;
//结构体定义

struct LNode{
	Elemtype data;
	struct LNode  *next;
};
typedef struct LNode* LNodePtr;
typedef struct LNode LNode1;

LNodePtr CreateListTail(int n){
	LNodePtr p,r;
	LNodePtr L=(LNodePtr)malloc(sizeof(struct LNode));
	L->next=NULL;
	L->data=0;
	r=L;
	for(int i=0;i<n;i++)
	{
		p=(struct LNode*)malloc(sizeof(LNode));
		p->data=i;
		r->next=p;
		r=p;
	}
	r->next=NULL;
	return L;//头结点的信息需要记录
}
void TraverseList(LNodePtr L)
{
	LNodePtr p;
	p=L;
	while(p->next!=NULL)
	{
		cout<<p->next->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	LNodePtr l1=CreateListTail(5);
	TraverseList(l1);
	return 0;
}