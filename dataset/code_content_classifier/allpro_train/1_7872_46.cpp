#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>
#include<stack>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<string> vstring;
typedef vector<pint> vpint;
typedef stringstream SS;

struct Edge{int to,from,cost;};

#ifdef DEBUG
#define debug cout
#else
SS ss;
#define debug ss
#endif

template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define rep(i,n) for(int i=0;i<(n);++i)
#define repn(i,m,n) for(int i=(m);i<=(n);++i)
#define repd(i,n) for(int i=(n)-1;i>=0;--i)
#define repnd(i,m,n) for(int i=(n);i>=(m);--i)
#define rep0(i,n) for(i=0;i<(n);++i)
#define repn0(i,m,n) for(i=(m);i<=(n);++i)
#define repd0(i,n) for(i=(n)-1;i>=0;--i)
#define repnd0(i,m,n) for(i=(n);i>=(m);--i)
#define all(n) n.begin(),n.end()
#define sz(n) ((int)(n).size())
#define IL for(;;)
#define MP make_pair
#define PB push_back
#define X second
#define Y first
#define PUTLINE debug<<"LINE:"<<__LINE__<<endl;

const int INF = 2147483647/3;
const double EPS = 1e-10;
const double PI = acos(-1.0);

const int dx[]={1,-1,0,0,1,-1,1,-1,0};
const int dy[]={0,0,1,-1,1,-1,-1,1,0};

int sq(int n){return n*n;}

int f(pint aa,pint bb){
	int a[4];
	a[0]=aa.first;
	a[1]=aa.second;
	a[2]=bb.first;
	a[3]=bb.second;
	sort(a,a+4);
	return sq(a[0]-a[1])+sq(a[1]-a[2])+sq(a[2]-a[3]);
}

int main() {
	int a,b;
	IL{
		cin>>a>>b;
		if(a==0&&b==0)break;
		vpint aa,bb;
		for(int i=1;i*i<=a;++i)if(a%i==0)aa.PB(MP(i,a/i));
		for(int i=1;i*i<=b;++i)if(b%i==0)bb.PB(MP(i,b/i));
		int mn=INF;
		rep(i,sz(aa))rep(j,sz(bb))chmin(mn,f(aa[i],bb[j]));
		cout<<mn<<endl;
	}
	return 0;
}