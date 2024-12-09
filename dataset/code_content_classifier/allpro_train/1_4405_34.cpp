#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mt make_tuple
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
//typedef tuple<int,int,int> tp;
//typedef vector<tp> vt;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-7;
const int inf=1e9;
const ll INF=2e18;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,k,m,r;
int out[10010];
void add(int a){
	int t=1;
	int co=0;
	while(t&&co<10010){
		out[co]+=t/a;
		t=t-t/a*a;
		t*=10;
		co++;
	}
	for(int i=10009;i>=1;i--){
		out[i-1]+=out[i]/10;
		out[i]%=10;
	}
}
void div(int a=n){
	int t=0;
	rep(i,10010){
		t*=10;
		t+=out[i];
		out[i]=t/a;
		t=t-t/a*a;
	}
}
int main(){
	while(cin>>n>>k>>m>>r,n){
		rep(i,10010)out[i]=0;
		if(m){
			loop(i,1,n)add(i);
			div();
		}
		add(n);
		cout<<out[0]<<".";
		rep(i,r)cout<<out[i+1];
		cout<<endl;
	}
}