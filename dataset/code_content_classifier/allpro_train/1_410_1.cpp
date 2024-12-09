#include<cstdio>
#include<map>
using namespace std;

#define ll long long

const int mod=1e9+7;
map<ll,ll> dp;

ll dfs(ll x)
{
    if(dp[x]) return dp[x];
    return dp[x]=(dfs(x/2)+dfs((x-1)/2)+dfs((x-2)/2))%mod;
}

int main()
{
    ll n;
    scanf("%lld",&n);
    dp[0]=1ll;dp[1]=2ll;
    printf("%lld",dfs(n));
    return 0;
}