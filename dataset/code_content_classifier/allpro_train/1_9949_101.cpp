#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int N, L;
	cin >> N >> L;
	vector<int> A(N);
	vector<pii> ps(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		ps[i] = { -A[i], i };
	}
	sort(ps.begin(), ps.end());
	vector<ll> res(N);
	for (int x = 0; x < N; x++) {
		int i = ps[x].second;
		if ((i - 1 < 0 || A[i - 1] < A[i]) && (i + 1 >= N || A[i + 1] < A[i])) {
			res[i] = L - A[i];
			continue;
		}
		int l = (i - 1 >= 0 ? A[i - 1] : 0), r = (i + 1 < N ? A[i + 1] : 0);
		if (l > A[i]) {
			res[i] = max(res[i], res[i - 1] + (L - A[i]));
		}
		if (r > A[i]) {
			res[i] = max(res[i], res[i + 1] + (L - A[i]));
		}
	}
	cout << *max_element(res.begin(), res.end()) << endl;
	return 0;
}

