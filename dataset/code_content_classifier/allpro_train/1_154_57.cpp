#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define rep(i,a,n) for(ll i =(a);i<(n);++i)
#define urep(i,a,n) for(ll i = (a);i>=(n);--i)
#define all(x) (x).begin(),(x).end()
#define INF 1e18
const int mod = 1e9 + 7;
typedef long long ll;
using namespace std;
ll dx[4] = { 1,-1,0,0 };
ll dy[4] = { 0,0,1,-1 };
ll N,M,X,Y,A,B,C,Q,K,R,W,H;
string S,T;
ll ans;
ll x[1000000];
ll y[1000000];
ll a[1000000];
ll b[1000000];
ll c[1000000];
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}
struct Edge{
	ll to,cost;
	 Edge(int to, int cost) : to(to), cost(cost) {}
};
typedef vector<vector<Edge> > AdjList;
AdjList graph;
vector<ll> dist;
int main() {
	ll y1,y2,m1,m2,d1,d2;
	cin>>y1>>m1>>d1>>y2>>m2>>d2;
	if(y1>y2){
		swap(y1,y2);
		swap(m1,m2);
		swap(d1,d2);
	}
	if(y1==y2){
		if(m1==m2 && d1==d2)cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	if(m1>m2 || (m1==m2 && d1>=d2)){
		cout<<y2-y1<<endl;
	}
	else{
		cout<<y2-y1+1<<endl;
	}
	return 0;
}

