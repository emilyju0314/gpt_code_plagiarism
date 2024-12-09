#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

lint a[6],d;
map<lint,lint> memo;

lint dfs(lint n){
	if(n==1) return d;

	if(memo.count(n)>0) return memo[n];

	lint res=INF;
	if(n<res/d) res=d*n;
	for(int x:{2,3,5}){
		lint next=n/x;
		if(1<=next && next<n) res=min(res,a[x]+d*(n-next*x)+dfs(next));
		next=(n+x-1)/x;
		if(1<=next && next<n) res=min(res,a[x]+d*(next*x-n)+dfs(next));
	}
	return memo[n]=res;
}

void solve(){
	lint n; cin>>n>>a[2]>>a[3]>>a[5]>>d;
	memo.clear();
	cout<<dfs(n)<<'\n';
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
