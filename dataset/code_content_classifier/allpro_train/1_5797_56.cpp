#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> a(N); rep(i, 0, N) {
		cin >> a[i]; a[i]--;
	}
	vector<int> b(N); rep(i, 0, N) {
		cin >> b[i]; b[i]--;
	}
	vector<bool> use(N); rep(i, 0, N) {
		use[b[i]] = true;
	}

	bool ok = true;
	rep(i, 0, N) {
		if (use[i] == false) {
			ok = false;
		}
	}
	if (ok) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
		vector<int> c(N);
		vector<int> d(N);
		iota(all(c), 1);
		iota(all(d), 1);
		rep(i, 0, N) {
			if (use[i] == false) {
				d[i]++;
				if (d[i] > N)d[i] = 1;
				break;
			}
		}
		cout << c[a[0]]; rep(i, 1, c.size()) { cout << " " << c[a[i]]; } cout << endl;
		cout << d[a[0]]; rep(i, 1, d.size()) { cout << " " << d[a[i]]; } cout << endl;
	}

	return 0;
}
