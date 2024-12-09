#include<bits/stdc++.h>
using namespace std;
const int N=55;
long long dp[N][N*N];      //dp值会爆int
int main()
{
    int n,a;
    cin>>n>>a;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=i-1;j>=0;j--)    //每一次个数向下减少
            for(int k=0;k<=N*j;k++)    //优化时间  由于k最大为N*j次
                dp[j+1][k+x]+=dp[j][k];       //个数加1 则找到前面个数的值相加
    }
    long long ans=0;       
    for(int i=1;i<=n;i++)
            ans+=dp[i][i*a];    //累计所有个数会出现平均值满足a的情况
    cout<<ans<<endl;
    return 0;
}