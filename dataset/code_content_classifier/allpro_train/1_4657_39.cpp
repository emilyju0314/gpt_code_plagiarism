#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#include <complex>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<long double,long double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<61;
const double pi=acos(-1);
const double eps=1e-10;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int n;
vvp g;
vl a,s;
vi used;

int t=-1,U,I;

int dfs(int v){
	used[v]=1;
	int S=1;
	for(int i=0;i<g[v].size();i++){
		P p=g[v][i];
		int u=p.first,ind=p.second;
		if(!used[u]){
			int T=dfs(u),tmp=n-2*T;
			if(tmp!=0) a[ind]=(s[u]-s[v])/tmp;
			else{
				t=v;U=T;I=ind;
			}
			S+=T;
		}
	}
	return S;
}

ll DFS(int v,ll L){
	used[v]=0;
	ll res=L;
	for(int i=0;i<g[v].size();i++){
		P p=g[v][i];
		int u=p.first,ind=p.second;
		if(used[u]) res+=DFS(u,L+a[ind]);
	}
	return res;
}

int main(){
	cin>>n;
	g=vvp(n);
	s=vl(n);
	a=vl(n-1);
	used=vi(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}
	for(int i=0;i<n;i++) cin>>s[i];
	dfs(0);
	if(t!=-1){
		ll L=DFS(t,0);
		a[I]=(s[t]-L)/U;
	}
	for(int i=0;i<n-1;i++) cout<<a[i]<<endl;
}