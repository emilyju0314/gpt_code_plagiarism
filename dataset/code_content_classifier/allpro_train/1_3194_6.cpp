#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)

vector<int>edge[105];
int n,k;
ll h[105],s[105],mn[105];

bool cmp(const int&a,const int&b){
	return mn[a] < mn[b];
}
int deq[200005];

vector<ll> rec(int v,vector<ll>dp){
	vector<ll>ret = dp, zan;
	ll pre = 0;
	for(int i=0;i<edge[v].size();i++){
		if(h[v] < mn[edge[v][i]]){
			break;
		}
		ll pl = mn[edge[v][i]]-pre;
		pre = mn[edge[v][i]];
		//dp -> [0,...,pl-1] で ret を更新
		//[l,r)
		int l=0,r=0;
		if(pl){
    		for(int i=0;i<=k;i++){
    			while(l<r && dp[deq[r-1]]-1LL*deq[r-1]*s[v] < dp[i]-1LL*i*s[v]){
    				r--;
    			}
    			deq[r++] = i;
    			if(deq[l] <= i-pl) l++;
    			ret[i] = max(ret[i],dp[deq[l]]+1LL*(i-deq[l])*s[v]);
    		}
		}
		zan = rec(edge[v][i],dp);
		for(int i=k;i>=pl;i--){
			zan[i] = zan[i-pl] + s[v] * pl;
		}
		for(int i=0;i<pl;i++){
			zan[i] = -INF;
		}
		dp = zan;
	}
	ll pl = h[v]-pre; //cout << pl << "n" << endl;
	//dp -> [0,...pl]で ret を更新
	//[l,r)
	int l=0,r=0;
	for(int i=0;i<=k;i++){
		while(l<r && dp[deq[r-1]]-1LL*deq[r-1]*s[v] < dp[i]-1LL*i*s[v]){
    		r--;
    	}
    	deq[r++] = i;
    	if(deq[l] < i-pl) l++;
    	ret[i] = max(ret[i],dp[deq[l]]+1LL*(i-deq[l])*s[v]);
    }
    //cout << v << " " << endl;
    //rep(i,k+1) cout << i << " " << ret[i] << endl;
	return ret;
}
int main(){
	while(1){
		cin >> n >> k;
		if(n == 0) return 0;
		for(int i=1;i<=n;i++){
			edge[i].clear();
		}
		repn(i,n){
			cin >> h[i];
			h[i] = min(h[i],1LL*k);
		}
		repn(i,n) cin >> s[i];
		for(int i=2;i<=n;i++){
			int p; cin >> p; edge[p].pb(i);
		}
		for(int i=2;i<=n;i++){
			cin >> mn[i]; //cout << mn[i] << " " << k << endl;
			mn[i] = min(mn[i],1LL*k);
		}
		for(int i=1;i<=n;i++) sort(edge[i].begin(),edge[i].end(),cmp);
		vector<ll>val;
		val.push_back(0);
		for(int i=0;i<k;i++) val.push_back(-INF);
		auto ret = rec(1,val);
		ll ans = -INF;
		rep(i,ret.size()) ans = max(ans,ret[i]);
		cout << ans << endl;
	}
}
