#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define H 200010
#define N 3010
using namespace std;

struct pt{int x,y;};

ll h,w,k,x,y,dx,dy,dp[N],fac[H],inv[H];
pt ps[N];

bool cmp(pt a,pt b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

ll bpow(ll a, ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=(ret*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ret;
}

ll ncr(ll n,ll r)
{
    return ((fac[n]*inv[n-r])%M*inv[r])%M;
}

int main()
{
    fac[0]=1;
    FOR(i,1,H) fac[i]=(fac[i-1]*i)%M;
    FOR(i,0,H) inv[i]=bpow(fac[i],M-2);
    cin>>h>>w>>k;
    FOR(i,0,k) cin>>ps[i].x>>ps[i].y;
    ps[k].x=1; ps[k].y=1;
    ps[k+1].x=h; ps[k+1].y=w;
    sort(ps,ps+k+2,cmp);
    dp[0]=1;
    FOR(i,1,k+2)
    {
        dp[i]=ncr(ps[i].x+ps[i].y-2,ps[i].x-1);
        FOR(j,1,i)
        {
            dx=ps[i].x-ps[j].x; dy=ps[i].y-ps[j].y;
            if(dx<0 || dy<0) continue;
            dp[i]=(dp[i]-(dp[j]*ncr(dx+dy,dx))%M+M)%M;
        }
    }
    cout<<dp[k+1]<<'\n';

    return 0;
}