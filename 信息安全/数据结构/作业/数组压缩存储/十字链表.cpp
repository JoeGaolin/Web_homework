#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define OK 1
#define error 0
#define OVERFLOW -1
using namespace std;

typedef struct OLNode{
    int i,j;
    int e;
    struct OLNode *right,*down;
}OLNode,*OLink;

typedef struct {
    OLink *rhead,*chead;
    int mu,nu,tu;//tu非零元个数
}CrossList;

int CreateSMatrix_OL(CrossList &M) {
    int m,n,t;
    cin>>m>>n>>t;
    M.mu=m; M.nu=n; M.tu=t;
    if(!(M.rhead=(OLink*)malloc((m+1)*sizeof(OLink)))) exit(OVERFLOW);
    if(!(M.chead=(OLink*)malloc((n+1)*sizeof(OLink)))) exit(OVERFLOW);
    for(int i=0;i<m+1;i++)
        M.rhead[i]=NULL;
    for(int i=0;i<n+1;i++)
        M.chead[i]=NULL;
    int i,j,e;
    for(scanf("%d%d%d",&i,&j,&e);i!=0;scanf("%d%d%d",&i,&j,&e))
    {
        OLNode *p,*q;
        if(!(p=(OLNode *)malloc(sizeof(OLNode)))) exit(OVERFLOW);
        p->i=i; p->j=j; p->e=e;
        if(M.rhead[i]==NULL or M.rhead[i]->j>j)
        {
            p->right=M.rhead[i]; M.rhead[i]=p;
        }
        else{
            for(q=M.rhead[i];(q->right)&&(q->right->j<j);q=q->right);
            p->right=q->right;q->right=p;
        }
        if(M.chead[j]==NULL||M.chead[j]->i>i) {
            p->down=M.chead[j]; M.chead[j]=p;
        }
        else{
            for(q=M.chead[j];(q->down)&&q->down->i<i;q=q->down) ;
            p->down=q->down; q->down=p;
        }
    }
    return OK;
}

int PrintMatrix(CrossList &M){
    //按行输出
    for(int i=1;i<M.mu+1;i++){
        OLNode *p=M.rhead[i];
        while(p){
            cout<<p->i<<" "<<p->j<<" "<<p->e<<"\n";
            p=p->right;
        }
    }
    return OK;
}
int main(){
    CrossList M;
    CreateSMatrix_OL(M);
    PrintMatrix(M);
    return 0;
}