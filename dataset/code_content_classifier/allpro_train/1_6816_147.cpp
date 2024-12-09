#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c),end(c)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
#define FORD(i,a,b) for (ll i=ll(b)-1; i>=(a); i--)
int main() {
	ios::sync_with_stdio(false);

	ll N; cin >> N;
	vl a(N);
	ll ges = 0;
	FOR(i,0,N) {
		cin >> a[i];
		ges ^= a[i];
	}

	FOR(i,0,N) {
		a[i] &= (~ges);
	}

	ll stelle = 0;
	FORD(i,0,61) {
		bool found = false;
		FOR(j,stelle,N) {
			if (a[j] & (1LL<<i)) {
				// bit is set
				found = true;
				swap(a[j],a[stelle]);
				break;
			}
		}
		if (found) {
			FOR(j,0,N) {
				if (j == stelle) {
					continue;
				}
				if (a[j] & (1LL << i)) {
					a[j] ^= a[stelle];
				}
			}
			stelle++;
		}
	}
	ll erg = 0LL;
	FOR(i,0,N) {
		erg ^= a[i];
	}
	
	cout << 2 * erg + ges << endl; 
	return 0;
}
