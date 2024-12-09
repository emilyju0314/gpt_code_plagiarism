#include <bits/stdc++.h>

using namespace std;

int N, E, T;
int A[100002];
long long dp[100002];
long long f[100002];
long long g[100002];

int main()
{
    scanf("%d%d%d", &N, &E, &T);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    A[N+1]=E;
    dp[0]=A[1];
    f[0]=dp[0]-3LL*A[1];
    g[0]=dp[0]-A[1];
    multiset<long long> s;
    s.insert(g[0]);
    int ptr=0;
    for(int i=1; i<=N; i++)
    {
        dp[i]=0x3f3f3f3f3f3f3f3fLL;
        while(ptr<i && T<2LL*(A[i]-A[ptr+1]))
        {
            s.erase(s.find(g[ptr]));
            ptr++;
        }
        if(ptr>0)
            dp[i]=min(dp[i], f[ptr-1]+2LL*A[i]);
        if(!s.empty())
            dp[i]=min(dp[i], *s.begin()+T);
        dp[i]+=A[i+1];
        f[i]=min(dp[i]-3LL*A[i+1], f[i-1]);
        g[i]=dp[i]-A[i+1];
        s.insert(g[i]);
    }
    printf("%lld\n", dp[N]);
    return 0;
}
