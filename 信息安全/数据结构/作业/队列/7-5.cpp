#include <iostream>
using namespace std;


struct people{
    int arrive_time;
    int ptime;
}queue[1001];

struct windows{
    int current=0;
    int wait_time[10001]={0};
}window[11];


int judge(int K,int arrive_time)
{
    int sum=0,top=-1;
    int a[11];
    for(int i=1;i<=K;i++)
    {
        if(arrive_time>window[i].current){
            a[++top]=i;
            sum++;
        } 
    }
    if(sum==0)//没一个窗口空闲
        return 0;
    if(sum>0)//多个窗口空闲
        return a[0];
}

int choose(int K)
{
    int pos=1,time=window[1].current;
    for(int i=2;i<=K;i++)
    {
        if(window[i].current<time)
        {
            time=window[i].current;
            pos=i;
        }
    }
    return pos;
}

int main()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>queue[i].arrive_time>>queue[i].ptime;
        queue[i].ptime=queue[i].ptime>60?60:queue[i].ptime;
    }
    int K,top[11]={0};
    cin>>K;

    //先逐个放置
    for(int j=1;j<=K;j++){
        window[j].current=queue[j].arrive_time+queue[j].ptime;
        top[j]++;
    }

    for(int i=K+1;i<=N;i++)
    {
        int tag=judge(K,queue[i].arrive_time);
        if(tag==0){//没一个窗口空闲
            int pos=choose(K);//选择最先空闲的窗口
            top[pos]++;//wait_time的长度
            window[pos].wait_time[top[pos]]=window[pos].current-queue[i].arrive_time;
            window[pos].current+=queue[i].ptime;
        }
        else{
            window[tag].current=queue[i].arrive_time+queue[i].ptime;
            top[tag]++;
        }

    }
    int sum_time=0,max_time=0,max_current=0;

    for(int i=1;i<=K;i++)
    {
        for(int j=1;j<=top[i];j++)
        {
            sum_time+=window[i].wait_time[j];
            if(max_time<window[i].wait_time[j])
                max_time=window[i].wait_time[j];
        }
        if(max_current<window[i].current)
            max_current=window[i].current;
        
    }
    printf("%.1f ",1.0*sum_time/N);
    cout<<max_time<<" "<<max_current<<endl;
    for(int i=1;i<K;i++)
        cout<<top[i]<<" ";
    cout<<top[K];
    return 0;
}