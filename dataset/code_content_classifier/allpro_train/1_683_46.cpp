#include <iostream>
#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)*/
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
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

class Graph{
	private:
	int n;
	vvp g;
	public:
	P DIJ(int s,int t,vi a){
		priority_queue<pip> q;
		vp d(n,{inf,0});
		d[s]={0,0};
		q.push({{0,0},s});
		while(!q.empty()){
			pip pp=q.top();q.pop();
			P p=pp.first;
			int v=pp.second,A=-p.first,B=-p.second;
			if(d[v]!=make_pair(A,B)) continue;
			for(auto i:g[v]){
				int u=i.first;
				A+=i.second,B+=a[u];
				if(d[u]>make_pair(A,B)){
					d[u]={A,B};
					q.push({{-A,-B},u});
				}
				A-=i.second,B-=a[u];
			}
		}
		return d[t];
	}
	void Init(int v){
		n=v;
		g=vvp(v);
	}
	void add_edge(int s,int t,int c){g[s].push_back({t,c});}
};

int n=0,m,T;
map<string,int> mp;
vi id;
Graph g;

int f(){
	string s;
	cin>>s;
	if(mp.find(s)==mp.end()) mp[s]=n++;
	return mp[s];
}

void E(vi a,vi b){
	int S=a.size();
	for(int i=0;i<S-1;i++){
		int u=a[i],v=a[i+1];
		if(u!=v) g.add_edge(id[u]++,id[v],b[i]);
		else g.add_edge(id[u],id[u]+1,b[i]),id[u]++;
	}
	id[a[S-1]]++;
}

int main(){
	cin>>m>>T;
	int s=f(),t=f();
	vvi a(m),b(m);
	for(int i=0;i<m;i++){
		int A;
		cin>>A;
		a[i]=vi(A);
		b[i]=vi(A-1);
		for(int j=0;j<A;j++) a[i][j]=f();
		for(int j=0;j<A-1;j++) cin>>b[i][j];
	}
	vi c(n,1);
	for(int i=0;i<m;i++) for(auto j:a[i]) c[j]+=2;
	int N=0;
	for(auto i:c) N+=i;
	g.Init(N);
	id=vi(n);
	for(int i=1;i<n;i++) id[i]=id[i-1]+c[i-1];
	for(int i=0;i<m;i++){
		E(a[i],b[i]);
		reverse(a[i].begin(),a[i].end());
		reverse(b[i].begin(),b[i].end());
		E(a[i],b[i]);
	}
	vi B(N);
	for(int i=0;i<n;i++){
		B[id[i]]++;
		for(int j=(i?id[i-1]+1:0);j<id[i];j++){
			g.add_edge(j,id[i],T);
			g.add_edge(id[i],j,0);
		}
	}
	P p=g.DIJ(id[s],id[t],B);
	if(p.first==inf) cout<<-1<<endl;
	else cout<<p.first-T<<' '<<p.second-1<<endl;
}
