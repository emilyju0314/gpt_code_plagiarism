#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<ll,int> P;
typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin>>n;
	ll m=1,cnt=1;
	while(m*2<=n) m*=2,cnt++;
	if(n==m*2-1) cout<<cnt<<endl;
	else cout<<cnt-1<<endl;

	return 0;
}

