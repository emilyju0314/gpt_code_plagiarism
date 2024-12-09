// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) rep(i,v.size())cout<<" "<<v[i];cout<<endl<<endl;
#define show2d(v) rep(i,v.size()){rep(j,v[i].size())cout<<" "<<v[i][j];cout<<endl;}cout<<endl;
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
//#define mt make_tuple
//typedef tuple<int,int,int> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};//ESWN
map<pii,int>ma;
class BRI{
	public:
		int N;
		vi used;
		vvi G;
		vp bridge;
		void add_edge(int s, int t){
			G[s].pb(t);
			G[t].pb(s);
		}
		BRI(int size){
			N=size;
			G=vvi(N);
		}
	int dfs(int i, int prev,int &n){
		if(used[i])return used[i];
		int m=n;
		used[i]=n++;
		rep(j,G[i].size()){
			if(prev==G[i][j])continue;
			if(used[i]<used[G[i][j]])continue;
			int res=dfs(G[i][j],i,n);
			m=min(m,res);
			if(used[i]<res)bridge.pb(pii(min(i,G[i][j]),max(i,G[i][j])));
		}
		return m;
	}
	void bri(){
		used=vi(N);
		bridge=vp(0);
		int n=1;
		dfs(0,-1,n);
		rep(i,bridge.size()){
			ma[bridge[i]]=true;
			ma[{bridge[i].second,bridge[i].first}]=true;
		}
	}	
};
vi sum,used,to,w,c;
vvi G,tG;
int t;
void dfs(int a){
	to[a]=t;
	sum[t]+=w[a];
	used[a]=true;
	c[t]++;
	rep(i,G[a].size())if(used[G[a][i]]==0){
		if(ma[{a,G[a][i]}])continue;
		dfs(G[a][i]);
	}
}
pii dfs1(int a){
	used[a]=1;
	int out1=0,out2=0;
	rep(i,tG[a].size())if(used[tG[a][i]]==0){
		pii t=dfs1(tG[a][i]);
		out1=max(out1,t.first);
		out2+=t.second;
	}
	if(out2||c[a]-1)out2+=sum[a];
	if(out2==0)out1+=sum[a];
	return {out1,out2};
}
int main(){
	int n,m;
	cin>>n>>m;
	w=vi(n);
	rep(i,n)cin>>w[i];
	BRI bri(n);
	while(m--){
		int a,b;
		cin>>a>>b;
		a--;b--;
		bri.add_edge(a,b);
	}
	bri.bri();
	
	t=0;
	used=to=vi(n);
	G=bri.G;
	rep(i,n)if(used[i]==0){
		sum.pb(0);
		c.pb(0);
		dfs(i);t++;
	}
	tG=vvi(sum.size());
	rep(i,bri.bridge.size()){
		pii a=bri.bridge[i];
		tG[to[a.first]].pb(to[a.second]);
		tG[to[a.second]].pb(to[a.first]);
	}
//	show2d(tG);
	used=vi(tG.size());
	pii out=dfs1(0);
	cout<<out.first+out.second<<endl;
}
	



