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
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1<<30;
map<int,int>ma;
int n,m;
ll f(int a,int b){
	if(b==n+1){
		return 0;
	}
	int t=ma[b];
	ll out;
	if(a==t)out=f(a,b+1);
	else if(t==1){
		out=f(a==2?0:2,b+1)+pow(3,n-b);
	}else{
		out=f(a,b+1)+pow(3,n-b)*2;
	}
	return out;
}
int main(){
	while(cin>>n>>m,n+m){
		rep(i,3){
			int a;cin>>a;
			rep(j,a){
				int b;cin>>b;
				ma[b]=i;
			}
		}
		ll out=min(f(0,1),f(2,1));
		cout<<out<<endl;
	}
}