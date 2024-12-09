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
#define show1d(v) rep(_,v.size())cout<<" "<<v[_];cout<<endl;
#define show2d(v) rep(_,v.size()){rep(__,v[_].size())cout<<" "<<v[_][__];cout<<endl;}cout<<endl;
using namespace std;
//kaewasuretyuui
typedef long long ll;
#define int ll
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
// #define mt make_tuple
// typedef tuple<int,int,int> tp;
// typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 1e18+10 : 1e9+10;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};//RDLU
map<pip,int>ma;
int n;
vvi in;
vvi f(int a){
	vvi w(n,vi(n));
	rep(i,n)rep(j,n){
		w[n-1-i][n-1-j]=a%2;
		a/=2;
	}
	return w;
}
int F(vvi w){
	int a=0;
	rep(i,n)rep(j,n){
		a*=2;
		a+=w[i][j];
	}
	return a;
}
vvi nex(vvi w){
	vvi ne(n,vi(n));
	rep(i,n)rep(j,n){
		int co=0;
		rep(k,8){
			int x=i+dx[k];
			int y=j+dy[k];
			if(x<0||y<0||x>=n||y>=n)continue;
			co+=w[x][y];
		}
		if(w[i][j]&&(co==2||co==3))ne[i][j]=1;
		if(w[i][j]==0&&co==3)ne[i][j]=1;
	}
	
	return ne;
}
signed main(){
	while(cin>>n,n){
		vs s(n);
		rep(i,n)cin>>s[i];
		int x,y;
		in=vvi(n,vi(n));
		rep(i,n)rep(j,n){
			if(s[i][j]-'.')in[i][j]=1;
			if(s[i][j]=='@')x=i,y=j;
		}
		ma.clear();
		ma[{F(in),{x,y}}]=1;
		queue<pip>que;
		que.push({F(in),{x,y}});
		while(!que.empty()){
			int w;pii p;
			w=que.front().first;
			p=que.front().second;
			que.pop();
			vvi fi=f(w);
			
			int cnt=ma[{w,p}];
			int co=0;
			rep(i,n)rep(j,n)if(fi[i][j])co++;
			if(co==1){
				cout<<cnt-1<<endl;
				goto end;
			}
			
			fi[p.first][p.second]=0;
			rep(k,8){
				int nx=p.first+dx[k];
				int ny=p.second+dy[k];
				if(nx<0||ny<0||nx>=n||ny>=n)continue;
				if(fi[nx][ny])continue;
				fi[nx][ny]=1;
				// show2d(fi);
				vvi ne=nex(fi);
				ne[nx][ny]=1;
				// show2d(ne);
				// cout<<endl;
				if(ma[{F(ne),{nx,ny}}]==0){
					ma[{F(ne),{nx,ny}}]=cnt+1;
					que.push({F(ne),{nx,ny}});
				}
				fi[nx][ny]=0;
			}
		}
		cout<<-1<<endl;
		end:;
	}
}







