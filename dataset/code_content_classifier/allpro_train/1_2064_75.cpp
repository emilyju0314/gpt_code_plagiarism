#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<algorithm>
#define ll long long
using namespace std;
ll dp[50][1<<17];
const ll mod=1e9+7;
int n,x,y,z;
int main()
{
scanf("%d%d%d%d",&n,&x,&y,&z);
memset(dp,0,sizeof(dp));
dp[0][0]=1;
ll ans=1;
int base=((1<<(x+y+z-1))|(1<<(y+z-1))|(1<<(z-1)));
for(int i=1;i<=n;i++)
    ans=ans*10%mod;
    int sta=(1<<(x+y+z))-1;
    for(int i=1;i<=n;i++)
    {
        for(int s=0;s<=sta;s++)
        {if(dp[i-1][s]==0)
        continue;
            for(int k=1;k<=10;k++)
            {
                int now=s<<k|(1<<k-1);
                now&=sta;
                if((now&base)!=base)
                    dp[i][now]=(dp[i][now]+dp[i-1][s])%mod;
            }
        }
    }
        for(int i=0;i<=sta;i++)
            ans=(ans-dp[n][i]+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
