#include <iostream>
#include <malloc.h>
using namespace std;

#define list_init_size 100
#define  listincrement 10
#define OK 1
#define error 0
#define OVERFLOW 0

typedef struct {
	int *elem;
	int length;
	int listsize;
}Sqlist;

int init_list(Sqlist &L)
{
	L.elem=(int *)malloc(list_init_size*sizeof(int));
	if(!L.elem) exit(OVERFLOW);
	L.length=0;
	L.listsize=list_init_size;
	return OK;                
}

int insert_list(Sqlist &L,int pos,int e)
{
	if(pos<1||pos>L.length+1) return error;
	if(L.length>L.listsize)
	{
		int *newbase;
		newbase=(int *)realloc(L.elem,(L.listsize+listincrement)*sizeof(int));
		if(!newbase) exit(OVERFLOW);
		L.elem=newbase;
		L.listsize+=listincrement;
	}
	int *p;
	int *q=&(L.elem[pos-1]);
	for(p=&(L.elem[L.length-1]);p>=q;p--)
		*(p+1)=*p;
	*q=e;
	++L.length;
	return OK;
}
int delete_list(Sqlist &L,int pos)
{
	if(pos<1||pos>L.length+1) return error;
	int *q;
	q=&(L.elem[pos-1]);
	int *p;
	p=L.elem+L.length-1;
	for(++q;q<=p;q++)
		*(q-1)=*q;

	L.length--;
	return OK;
}
int main()
{
	Sqlist L;
	init_list(L);
	for(int i=0;i<=9;i++)
		insert_list(L,i+1,i);
	delete_list(L,5);
	for(int i=0;i<=L.length-1;i++)
	{
		cout<<L.elem[i]<<" ";
	}
	return 0;
}