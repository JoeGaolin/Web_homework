#include <iostream>
#include <string.h>
using namespace std;

#define OK 1
#define error 0
#define OVERFLOW -1
typedef struct
{
    char *base;
    char *top;
    int stacksize;
}stack;

void initstack(stack &st,int l)
{
    st.base=new char[l];
    if(!st.base)
        exit(OVERFLOW);
    st.top=st.base;
    st.stacksize=l;
}
int push(stack &st,char e)
{
    if((st.top-st.base)==st.stacksize)
        return error;
    *(st.top++)=e;
    return OK;
}
int pop(stack &st)
{
    if(st.top==st.base)
        return error;
    st.top--;
    return OK;
}
bool isright(string ss,int size)
{
    stack st;
    int flag=1;
    initstack(st,size);
    for(int  i=0;ss[i]!='\0';i++)
    {
        if(ss[i]=='S')
        {
            if(push(st,ss[i]))
                continue;
            else
            {
                flag=0;
                break;
            }
        }
        else
        {
            if(pop(st))
                continue;
            else
            {
                flag=0;
                break;
            }
        }
    }
    //操作完后应该为空栈
    if(st.top!=st.base)
        flag=0;
    if(flag) return true;
    else return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int result[100]={0};
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(isright(s,m))
            result[i]=1;
        else
            result[i]=0;
    }
    for(int i=0;i<n-1;i++)
    {
        if(result[i]==1)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    if(result[n-1]==1)
        cout<<"YES";
    else 
        cout<<"NO";
    return 0;
}