#include <bits/stdc++.h>
#define MOD 1000000009LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll fact[3000005];
ll extgcd(ll a,ll b,ll& x,ll &y){
	ll d=a;
	if(b!=0LL){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;
		y=0;
	}
	return d;
}

ll mod_inverse(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

ll mod_fact(ll n,ll p,ll &e){
	e=0;
	if(n==0)return 1;
	ll res=mod_fact(n/p,p,e);
	e+=n/p;
	if(n/p%2!=0){
		return res*(p-fact[n%p])%p;
	}
	return res*fact[n%p]%p;
}

ll mod_comb(ll n,ll k,ll p){
	if(n<0 || k<0 || n<k)return 0;
	ll e1,e2,e3;
	ll a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
	if(e1>e2+e3)return 0;
	return a1*mod_inverse(a2*a3%p,p)%p;
}

int n,m;
int a[20],b[20],c[20];
ll dp[1000005];
vector<int> G[3000005];
bool used[3000005];
int siz[5];
int now=0;

void dfs(int v){
	now++;
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(!used[G[v][i]]){
			dfs(G[v][i]);
		}
	}
}

int main(void){
	scanf("%d%d",&n,&m);
	fact[0]=1;
	for(ll i=1;i<=n*3;i++){
		fact[i]=fact[i-1]*i%MOD;
	}
	dp[0]=1;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]*mod_comb(i*3,3,MOD)%MOD;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i]*mod_inverse(fact[i],MOD)%MOD;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		a[i]--;
		b[i]--;
	}
	ll ans=0;
	for(int i=0;i<(1<<m);i++){
		queue<int> que,cla;
		bool flag=true;
		int cnt=0;
		for(int j=0;j<m;j++){
			if(i>>j & 1){
				G[a[j]].push_back(b[j]);
				G[b[j]].push_back(a[j]);
				que.push(a[j]);
				que.push(b[j]);
				cla.push(a[j]);
				cla.push(b[j]);
				if(c[j]==1){
					cnt++;
				}
			}else{
				if(c[j]==0)flag=false;
			}
		}
		if(flag){
			bool ng=false;
			memset(siz,0,sizeof(siz));
			while(que.size()){
				int v=que.front();
				que.pop();
				if(!used[v]){
					now=0;
					dfs(v);
					if(now>=4){
						ng=true;
					}else{
						siz[now]++;
					}
				}
			}
			if(ng)goto bye;
			siz[1]=3*n-siz[2]*2-siz[3]*3;
			ll val=1;
			while(siz[2]>0){
				val=val*siz[1]%MOD;
				siz[1]--;
				siz[2]--;
			}
			val=val*dp[siz[1]/3]%MOD;
			if(cnt%2==0){
				ans=(ans+val)%MOD;
			}else{
				ans=(ans-val+MOD)%MOD;
			}
		}
		bye:
		while(cla.size()){
			int v=cla.front();
			cla.pop();
			used[v]=false;
			G[v].clear();
		}
	}
	printf("%lld\n",ans);
	return 0;
}
