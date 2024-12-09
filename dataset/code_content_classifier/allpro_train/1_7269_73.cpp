//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

signed main(void)
{
	int n, k;
	cin >> n >> k;
	
	ll low = 0, high = 1e18;
	while(high-low>1) {
		ll mid = (high+low)/2, tmp = mid;
		//cout << high << " " << mid << " " << low << endl;
		bool flag = false;
		REP(i, n-1) {
			tmp -= (tmp-1)/k+1;
			if(tmp <= 0) flag = true;
		}
		if(flag) low = mid;
		else high = mid;
	}
	cout << low << endl;

	return 0;
}