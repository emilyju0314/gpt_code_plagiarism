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
#define mt make_tuple
typedef tuple<int,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
ll gcd(ll a,ll b){
	return (b==0?a:gcd(b,a%b));
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
int main(){
	int q;
	cin>>q;
	while(q--){
		int n;cin>>n;
		vs in(n);
		rep(i,n)cin>>in[i];
		
		rep(i,n){
			int t=in[i].size()/2;
			rep(j,in[i].size())if(in[i][j]!='0')t=gcd(t,j/2);
			if(t==0){
				in[i]="00";
			}else{
				string w="";
				rep(j,in[i].size()/t/2){
					w+=in[i][j*2*t];
					w+=in[i][j*2*t+1];
				}
				in[i]=w;
			}
		}
		ll t=1;
		rep(i,n){
			t=lcm(t,in[i].size());
			if(t>2048)break;
		}
//		rep(i,n)cout<<in[i]<<endl;cout<<endl;
		if(t>2048)cout<<"Too complex."<<endl;
		else{
			rep(i,n){
				int w=t/in[i].size();
				string a="";
				rep(j,in[i].size()/2){
					a+=in[i][2*j];
					a+=in[i][2*j+1];
					a+=string(2*w-2,'0');
				}
				in[i]=a;
			}
			rep(i,t){
				int s=0;
				rep(j,n)s+=in[j][i]-'0';
				printf("%01X",s);
			}
			cout<<endl;
		}
	}
}





