#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7,N=1e5+5;
int n,k,a[N];
ll f[N],invf[N];
ll C(ll n,ll m)
{
    return f[n]*invf[n-m]%mod*invf[m]%mod;
}
int main()
{
    f[0]=invf[0]=invf[1]=1;
    for(int i=1;i<N;i++)
        f[i]=f[i-1]*i%mod;
    for(int i=2;i<N;i++)
        invf[i]=(mod-mod/i)*invf[mod%i]%mod;
    for(int i=2;i<N;i++)
        invf[i]=invf[i]*invf[i-1]%mod;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    ll ans=0;
    for(int i=1;i<=n;i++)
        if(n-i>=k-1)
        ans=(ans-a[i]*C(n-i,k-1)%mod)%mod;
    for(int i=n;i>=1;i--)
        if(i-1>=k-1)
        ans=(ans+a[i]*C(i-1,k-1)%mod)%mod;
    ans=(ans+mod)%mod;
    printf("%lld\n",ans);
}
