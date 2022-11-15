#include<bits/stdc++.h>
using namespace std;
int dp[105][100005];
int w[105];
long long sum=0;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        sum=sum+w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)//逆向思维，筛选
        {
            if(j==w[i])
            {
                dp[i][j]=dp[i][j-1]+1;
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][abs(j-w[i])]+dp[i-1][j+w[i]];
            }
        }
    }
    int ans=0;
    for(int i=1;i<=sum;i++)
    {
        if(dp[n][i])
        ans++;
    }   
    cout<<ans;
    return 0;
}