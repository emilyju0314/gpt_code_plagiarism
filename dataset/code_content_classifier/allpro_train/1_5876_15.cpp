#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <complex>
#include <cassert>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
int N;
double x[100],y[100],z[100],r[100];
vector<double> zs;
double sq(double a,double b){return (a-b)*(a-b);}
double dist(int a,int b){return sqrt(sq(x[a],x[b])+sq(y[a],y[b])+sq(z[a],z[b]));}
int par[100];
void init(int N){rep(i,N) par[i]=i;}
int find(int x){
	if(x==par[x]) return x;
	return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x),y=find(y);
	par[x]=y;
}
int cut(double a){
	double rr[100]={};
	bool is[100]={};
	rep(i,N) if(z[i]-r[i]<a&&a<z[i]+r[i]){
		is[i]=1;
		rr[i]=sqrt(r[i]*r[i]-sq(z[i],a));
	}
	init(N);
	rep(i,N) rep(j,i){
		if(!is[i]||!is[j]) continue;
		if(sqrt(sq(x[i],x[j])+sq(y[i],y[j]))<rr[i]+rr[j]) unite(i,j);
	}
	set<int> ps;
	rep(i,N) if(is[i]) ps.insert(find(i));
	return ps.size();
}
int main(){
	while(true){
		cin>>N;
		if(N==0) break;
		zs.clear();
		rep(i,N) cin>>x[i]>>y[i]>>z[i]>>r[i];
		rep(i,N) zs.pb(z[i]-r[i]),zs.pb(z[i]+r[i]);
		rep(i,N) rep(j,i){
			double d=dist(i,j);
			if(d>r[i]+r[j]) continue;
			if(abs(r[i]-r[j])>d) continue;
			double theta=acos( (r[i]*r[i]+d*d-r[j]*r[j])/(2.0*r[i]*d) );
			double phi=atan2( z[j]-z[i],sqrt(sq(x[i],x[j])+sq(y[i],y[j])) );
			zs.pb(z[i]+r[i]*sin(theta+phi));
			zs.pb(z[i]+r[i]*sin(-theta+phi));
		}
		sort(all(zs));
		int now=0;
		string ans;
		for(double a:zs){
			int t=cut(a+1e-4);
			if(t==now+1){
				ans+='1';
			}else if(t==now-1){
				ans+='0';
			}else if(t==now){
			}else{
				assert(0);
			}
			now=t;
		}
		cout<<ans.size()<<endl<<ans<<endl;
	}
}