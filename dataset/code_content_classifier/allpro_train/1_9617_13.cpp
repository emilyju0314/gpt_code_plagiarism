#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#include "benri.h"
#else
#define out(args...)
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353
const ll INF=1e10;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vv<int> g(n);
	rep(i,n-1){
		int a,b;
		cin>>a>>b; --a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<int> a(n),b(n);
	for(int &x:a) cin>>x;
	for(int &x:b) cin>>x;
	vector<ll> dif(n);
	rep(i,n) dif[i]=b[i]-a[i];
	vector<ll> sum(n);
	{
		function<void(int,int)> dfs=
			[&](int v,int p){
				ll s=0;
				for(int w:g[v])if(w!=p){
						dfs(w,v);
						s+=sum[w];
					}
				s+=dif[v];
				sum[v]=s;
			};
		dfs(0,-1);
	}
	vector<ll> cnt(n);
	{
		function<void(int,int)> dfs=
			[&](int v,int p){
				for(int w:g[v])if(w!=p){
						cnt[w]=-sum[w]+cnt[v];
						dfs(w,v);
					}
			};
		dfs(0,-1);
		out(cnt,1);
	}
	auto mn=*min_element(all(cnt));
	for(auto &x:cnt) x-=mn;
	out(cnt,1);
	cout<<accumulate(all(cnt),0ll) NL;
  return 0;
}

