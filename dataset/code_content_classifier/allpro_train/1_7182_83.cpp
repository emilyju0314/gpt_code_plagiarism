#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll mod = 1e9 + 7;
const ll b1 = 1009, b2 = 10007;

ll Pow(ll a, ll b) {
	ll res = 1; a %= mod;
	while (b) {
		if (b & 1) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

class RollingHash {
	int N;
	string s;
	vector<ll> r1, r2, h1, h2, rh1, rh2;
public:
	RollingHash(const string& s_)
		: N((int)s_.size()), s(s_), r1(N + 1), r2(N + 1), h1(N + 1), h2(N + 1), rh1(N + 1), rh2(N + 1) {
		r1[0] = r2[0] = 1;
		for (int i = 1; i <= N; i++) r1[i] = r1[i - 1] * b1 % mod;
		for (int i = 1; i <= N; i++) r2[i] = r2[i - 1] * b2 % mod;

		h1[0] = h2[0] = 1;
		for (int i = 1; i <= N; i++) h1[i] = (h1[i - 1] * b1 + s[i - 1]) % mod;
		for (int i = 1; i <= N; i++) h2[i] = (h2[i - 1] * b2 + s[i - 1]) % mod;
	}
	P get(int l, int r) {
		return P((h1[r + 1] - h1[l] * r1[r - l + 1] % mod + mod) % mod, (h2[r + 1] - h2[l] * r2[r - l + 1] % mod + mod) % mod);
	}
};

int main()
{
	int n, m, l = 0, r = 0;
	string S, q;
	cin >> n >> m;
	cin >> S;
	RollingHash rh(S);
	vector<P> res;
	while (m--) {
		cin >> q;
		if (q == "R++") {
			r++;
		}
		if (q == "R--") {
			r--;
		}
		if (q == "L++") {
			l++;
		}
		if (q == "L--") {
			l--;
		}
		res.push_back(rh.get(l, r));
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	cout << res.size() << endl;
	return 0;
}