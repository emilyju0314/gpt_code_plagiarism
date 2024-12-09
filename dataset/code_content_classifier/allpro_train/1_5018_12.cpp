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
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
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
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<58;
const double pi=acos(-1);
const double eps=1e-7;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

const int M=300005;

vector<ull> Mod(M);

class Graph{
	private:
	int V;
	vvi g;
	vi DIJ(int s){
		priority_queue<P> q;
		vi d(V,inf);
		d[s]=0;
		q.push({0,s});
		while(!q.empty()){
			P p=q.top();
			q.pop();
			int v=p.second;
			if(d[v]<-p.first) continue;
			for(int i=0;i<g[v].size();i++){
				int u=g[v][i];
				if(d[u]>d[v]+1){
					d[u]=d[v]+1;
					q.push({-d[u],u});
				}
			}
		}
		return d;
	}
	public:
	Graph(int v){
		V=v;
		g=vvi(v);
	}
	void add_edge(int s,int t){
		g[s].push_back(t);
		g[t].push_back(s);
	}
	pair<ull,int> Hash_f(int v,vi& used,vi& dep){
		used[v]=1;
		ull H=dep[v];
		int S=0,I=1;
		vector<pair<ull,int> > a;
		for(int i=0;i<g[v].size();i++){
			int u=g[v][i];
			if(!used[u]){
				a.push_back(Hash_f(u,used,dep));
				S++;
			}
		}
		sort(a.begin(),a.end());
		for(int i=0;i<S;i++){
			H+=a[i].first*Mod[I];
			I+=a[i].second;
		}
		return make_pair(H,I);
	}
	ull Hash(){
		vi d=DIJ(0);
		int v,m=-1;
		for(int i=0;i<V;i++) if(d[i]>m){
			m=d[i];
			v=i;
		}
		d=DIJ(v);
		int u;
		m=-1;
		for(int i=0;i<V;i++) if(d[i]>m){
			m=d[i];
			u=i;
		}
		vi D=DIJ(u);
		ull H=0;
		for(int i=0;i<V;i++) if(d[i]+D[i]==d[u]&&abs(d[i]-D[i])<=1){
			vi used(V),dep=DIJ(i);
			H+=Hash_f(i,used,dep).first;
		}
		return H;
	}
	int dfs(int v,vi& used,vp& e){
		used[v]=1;
		int S=1;
		for(int i=0;i<g[v].size();i++){
			int u=g[v][i];
			if(!used[u]){
				S+=dfs(u,used,e);
				e.push_back({v,u});
			}
		}
		return S;
	}
	void Init(){
		Mod[0]=1;
		for(int i=1;i<M;i++) Mod[i]=Mod[i-1]*mod;
	}
	int solve(Graph G,int N){
		vi used(N);
		int res=0;
		Init();
		ull H=Hash();
		for(int i=0;i<N;i++) if(!used[i]){
			vp e;
			int N_=G.dfs(i,used,e);
			Graph G_(N_);
			map<int,int> m;
			int cnt=0;
			for(int i=0;i<N_-1;i++){
				int v=e[i].first,u=e[i].second;
				if(m.find(v)==m.end()) m[v]=cnt++;
				if(m.find(u)==m.end()) m[u]=cnt++;
				G_.add_edge(m[v],m[u]);
			}
			if(G_.Hash()==H) res++;
		}
		return res;
	}
};

int n1,m,n2;

int main(){
	cin>>n1>>m;
	Graph g(n1);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g.add_edge(u-1,v-1);
	}
	cin>>n2;
	Graph G(n2);
	for(int i=1;i<n2;i++){
		int u,v;
		cin>>u>>v;
		G.add_edge(u-1,v-1);
	}
	cout<<G.solve(g,n1)<<endl;
}