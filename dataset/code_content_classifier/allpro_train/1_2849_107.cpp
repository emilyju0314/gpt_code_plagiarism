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

ll a[1010];
signed main(void)
{
	while(true) {
		int n;
		cin >> n;
		if(!n) break;
		fill(a, a+1010, LLINF);
		bool xx = false, ng = false;
		REP(i, n) {
			string s;
			cin >> s;
			if(s == "x") {
				if(xx) ng = true;
				xx = true;
				continue;
			}
			a[i] = stoi(s);
			xx = false;
		}
		if(ng) {cout << "none" << endl; continue;}

		ll ma = LLINF, mi = -LLINF;
		bool conf = false;
		REP(i, n) {
			if(a[i] == LLINF) {
				if((i+1)%2) {
					if(i != 0) ma = min(ma, a[i-1]-1);
					if(i != n-1) ma = min(ma, a[i+1]-1);
				} else {
					mi = max(mi, a[i-1] + 1);
					if(i != n-1) mi = max(mi, a[i+1]+1);
				}
			} else {
				ng = false;
				if((i+1)%2) {
					if(i && a[i-1] != LLINF) ng |= (a[i] >= a[i-1]);
					if(i != n-1 && a[i+1] != LLINF) ng |= (a[i] >= a[i+1]);
				} else {
					if(a[i-1] != LLINF) ng |= (a[i] <= a[i-1]);
					if(i != n-1 && a[i+1] != LLINF) ng |= (a[i] <= a[i+1]);
				}
				if(ng) {
					cout << "none" << endl;
					conf = true;
					break;
				}
			}
		}
		if(conf) continue;

		if(ma < mi) cout << "none" << endl;
		else if(ma == mi) cout << ma << endl;
		else cout << "ambiguous" << endl;
	}

	return 0;
}