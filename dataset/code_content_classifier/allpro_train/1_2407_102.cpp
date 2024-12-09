#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+10;

vector<int> g[N];
vector<ll> d(N);

void dfs(int x,int p,ll cnt){
	d[x]+=cnt;
	for(int v:g[x]){
		if(v!=p) dfs(v,x,d[x]);
	}
}

int main(){
	int n,q;
	cin>>n>>q;

	for(int i = 0; i < n-1; i++){
		int a,b;
		cin>>a>>b;
		--a,--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i = 0; i < q; i++){
		int p,x;
		cin>>p>>x;
		d[--p] += x;
	}

	dfs(0,-1,0);

	for(int i = 0; i < n; i++){
		cout<<d[i]<<" ";
	}
}