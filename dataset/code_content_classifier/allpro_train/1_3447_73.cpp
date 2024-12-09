#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll N=1000005;
const ll mod=924844033;
const ll g=5;
ll ksm(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
ll fact[N+2],inv[N+2];
void Init(){
    fact[0]=inv[1]=1;
    for(ll i=1;i<=N;i++)
        fact[i]=fact[i-1]*i%mod;
    for(ll i=2;i<=N;i++)
        inv[i]=((mod-mod/i)*inv[mod%i])%mod;
    inv[0]=1;
    for(ll i=1;i<=N;i++)
        inv[i]=inv[i-1]*inv[i]%mod;
}
struct node{
    ll u,v,nxt;
}edge[N*2];
ll head[N],mcnt;
void add_edge(ll u,ll v){
    mcnt++;
    edge[mcnt].u=u;
    edge[mcnt].v=v;
    edge[mcnt].nxt=head[u];
    head[u]=mcnt;
}
ll sz[N];
ll cnt[N];
ll n;
void dfs(ll u,ll fa){
    sz[u]=1;
    for(ll i=head[u];i;i=edge[i].nxt){
        ll v=edge[i].v;
        if(v==fa)
            continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    cnt[sz[u]]--;
    cnt[n-sz[u]]--;
}
void NTT(ll a[],ll n,ll mode){
	for(ll i=0,j=0;i<n;i++)
	{
		if(i<j) swap(a[i],a[j]);
		ll k=(n>>1);
		while(k&&(k&j)){ j^=k; k>>=1; }
		j^=k;
	}
	for(ll i=1;i<n;i<<=1)
	{
		ll w1=ksm(g,(mod-1)/(i<<1)),w=1;
		if(mode==-1) w1=ksm(w1,mod-2);
		for(ll j=0;j<i;j++,w=1ll*w*w1%mod)
			for(ll l=j,r=l+i;l<n;l+=(i<<1),r=l+i)
			{
				ll temp=1ll*w*a[r]%mod;
				a[r]=(a[l]-temp+mod)%mod;
				a[l]=(a[l]+temp)%mod;
			}
	}
	if(mode==-1)
	{
		ll inv=ksm(n,mod-2);
		for(ll i=0;i<n;i++) a[i]=1ll*a[i]*inv%mod;
	}
}
ll a[N];
ll b[N];
int main()
{
    //freopen("calculate.in","r",stdin);
    //freopen("calculate.out","w",stdout);
    Init();
    scanf("%lld",&n);
    for(ll i=1;i<n;i++){
        ll u,v;
        scanf("%lld%lld",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(1,0);
    ll len=1;
    cnt[n]=n;
    for(;len<=n*2;len<<=1) ;
    for(ll i=0;i<=n;i++){
        a[i]=cnt[i]*fact[i]%mod;
        b[i]=inv[n-i];
    }
    NTT(a,len,1);
    NTT(b,len,1);
    for(ll i=0;i<=len;i++)
        a[i]=a[i]*b[i]%mod;
    NTT(a,len,-1);
    for(ll i=1;i<=n;i++){
        ll ans=a[n+i]*inv[i]%mod;
        ans=(ans%mod+mod)%mod;
        printf("%lld\n",ans);
    }
}
