// F - Enclosed Points
#include <bits/stdc++.h>

using namespace std;

#define	MOD	998244353

long long mpow(long long x, long long n)
{
	long long r = 1;
	for ( ; n > 0; x = x * x % MOD, n >>= 1) if (n & 1) r = r * x % MOD;
	return r;
}

void fen_update(vector<int> &tree, int i, int val)
{
	for ( ; i > 0 && i < tree.size(); i += i & -i) tree[i] += val;
}

int fen_get(vector<int> &tree, int i)
{
	int sum = 0;
	for ( ; i > 0; i &= i - 1) sum += tree[i];
	return sum;
}

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	long long n;
	cin >> n;
	vector<int> b;
	vector<pair<int, int> > a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second, b.push_back(a[i].second);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	map<int, int> m;
	for (int i = 0; i < b.size(); i++) m[b[i]] = i;

	long long ans = n * mpow(2, n - 1) % MOD;

	vector<int> l(n + 1), r(n + 1);
	for (int i = 0; i < n; i++)  fen_update(r, i + 1, 1);

	for (int i = 0; i < n; i++) {
		int y = m[a[i].second];
		fen_update(r, y + 1, -1);
		long long l1 = fen_get(l, y), l2 = i - l1;
		long long r1 = fen_get(r, y), r2 = n - 1 - i - r1;
		long long t1 = (mpow(2, l1) - 1 + MOD) % MOD * (mpow(2, r2) - 1 + MOD) % MOD * mpow(2, l2 + r1) % MOD;
		long long t2 = (mpow(2, l2) - 1 + MOD) % MOD * (mpow(2, r1) - 1 + MOD) % MOD * mpow(2, l1 + r2) % MOD;
		long long d = (mpow(2, l1) - 1 + MOD) % MOD * (mpow(2, r2) - 1 + MOD) % MOD * (mpow(2, l2) - 1 + MOD) % MOD * (mpow(2, r1) - 1 + MOD) % MOD;
		ans = (ans + t1 + t2 -d + MOD) % MOD;
		fen_update(l, y + 1, 1);
	}

	cout << ans << endl;

	return 0;
}
