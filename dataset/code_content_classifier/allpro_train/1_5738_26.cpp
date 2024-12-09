#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mem0(x) memset(x,0,sizeof(x))
#define meminf(x) memset(x,0x3f,sizeof(x))
#define VI vector<int>
#define VL vector<ll>
#define pb push_back
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define endl '\n'
#define pb push_back
#define fi first 
#define se second

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
//#define DEBUG
using namespace  std;


const int N = 2e5+5, inf = 0x3f3f3f3f;
const int M  = 2e7+5;
ll n,p;
ll a[N];

pii loc[N];
int vis[N];
void solve(){
	cin>>n>>p;
	rep(i,1,n){
		cin>>a[i];
		loc[i] ={a[i],i};
		vis[i] = 0;
	}
	
	sort(loc+1,loc+1+n);
	ll cnt = 0;
	ll ans = 0;
	rep(i,1,n){
		if(loc[i].fi >= p) break;
		if(vis[loc[i].se]) continue;
		int id1 = loc[i].se-1, id2 =loc[i].se+1;
		
		while(id1>=1 && !vis[id1] && a[id1]%loc[i].fi==0) vis[id1--] =1,vis[loc[i].se]=1;
		while(id2<=n && !vis[id2] && a[id2]%loc[i].fi==0) vis[id2++] =1,vis[loc[i].se]=1;
		
		ll tcnt = id2-id1-1;
		cnt += tcnt-1;
		//dump(loc[i].se);dump(tcnt);
		//dump((tcnt-1)*loc[i].fi);
		ans +=(tcnt-1)*loc[i].fi;
		
		if(id1>=1 && vis[id1] && a[id1]%loc[i].fi==0) cnt++,ans += loc[i].fi,vis[loc[i].se]=1;
		if(id2<=n && vis[id2] && a[id2]%loc[i].fi==0) cnt++,ans += loc[i].fi,vis[loc[i].se]=1;
		
	}
	
	
	
	ans += (n-cnt-1)*p;
	cout << ans <<endl;
}

int main(){
    ios::sync_with_stdio(0);
    int tt;cin>>tt;
    while(tt--){
        solve();
    }
}