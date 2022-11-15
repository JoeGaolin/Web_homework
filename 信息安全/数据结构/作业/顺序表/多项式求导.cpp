#include <iostream>
#include <stdio.h>
using namespace std;

struct term{
    int a,b;
};

int main()
{
    term data[1000];
    int cnt=0;
    //载入
    while(scanf("%d %d",&data[cnt].a,&data[cnt].b)==2)
    {
        
        data[cnt].a=data[cnt].a*data[cnt].b;
        data[cnt].b-=1;
        cnt++;
    }
    if(data[0].a==0)
        {
            cout<<"0 0";
            return 1;
        }
    else
    {
        for(int i=0;i<cnt-2;i++)
        {
            if(data[i].b>=0)
                cout<<data[i].a<<" "<<data[i].b<<" ";
        }


        if(data[cnt-1].a==0)
            cout<<data[cnt-2].a<<" "<<data[cnt-2].b;
        else
            cout<<data[cnt-2].a<<" "<<data[cnt-2].b<<" "<<data[cnt-1].a<<" "<<data[cnt-1].b;
    }
    return 0;
}