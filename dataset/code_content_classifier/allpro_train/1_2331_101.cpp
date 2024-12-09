#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*2LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

#define int ll
void solve() {
	vector<int> inputs;
	REP(i, 9) {
		string s;
		cin >> s;
		inputs.push_back(0);
		REP(i, s.length()) {
			inputs.back() *= 16;
			if (s[i] >= 'a') {
				inputs.back() += s[i] - 'a' + 10;
			}
			else {
				inputs.back() += s[i] - '0';
			}
		}
	}
	int key = 0;
	for (int i = 0; i < 32; ++i) {
		int tmp = 0;
		REP(q, inputs.size() - 1) {
			tmp += inputs[q] ^ key;
		}
		tmp &= (1LL << (long long)(i + 1)) - 1LL;
		if (((inputs[8]^key) & ((1LL << (long long)(i + 1)) - 1LL)) == tmp) {
			key += 0;
		}
		else {
			key += (1LL << i);
		}
	}
	string ans;
	while (key != 0) {
		int hoge = key % 16;
		key /= 16;
		if (hoge <= 9) {
			ans.push_back(hoge + '0');
		}
		else {
			ans.push_back(hoge - 10 + 'a');
		}
	}
	if (ans.length() == 0) ans.push_back('0');
	reverse(ALL(ans));
	cout << ans << endl;
}

#undef int
int main() {
	init();
	int t;
	cin >> t;
	REP(tea,t)
	solve();
}
