#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<map>
#include<set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef stack<int> SI;
typedef queue<int> QI;
typedef pair<int,int> PII;
typedef long long LL;

#define d(x)  cout<<#x<<" = "<<(x)<<endl;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define EMP empty()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define REACH(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c,n) sort(c,c+n)
#define VSORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define DFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define DREP(i,n) DFOR(i,n,0)
#define INF 1000000000

const double EPS = 1e-10;
const double PI  = acos(-1.0);
////////////////////////////////////////////////
struct Vector{int x;int y;};

int cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
int scaler(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}

int main()
{
	int n;cin>>n;
	REP(i,n)
	{
		Vector a,b;
		int x0,y0,x1,y1,x2,y2,x3,y3;
		cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;
		a.x=x1-x0;
		a.y=y1-y0;
		b.x=x3-x2;
		b.y=y3-y2;
		if(cross(a,b)==0)cout<<2<<endl;
		else if(scaler(a,b)==0)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}