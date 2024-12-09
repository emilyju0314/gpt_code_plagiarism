#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main()
{
	int h, w, n;
	cin >> h >> w >> n;
	vector<P> ab(n);
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		ab[i] = { a, b };
	}
	sort(ab.begin(), ab.end());
	vector<int> val(w);
	for (int i = 0; i < w; i++) {
		val[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int c = ab[i].first - 1; c = (-c % (w * 2) + w * 2) % (w * 2);
		int l = ab[i].second - 1;
		int r = ab[i].second;
		int v = ((l & 1) != (c & 1) ? w * 2 - 1 - l + c : l + c) % (w * 2);
		l = v >= w ? w * 2 - 1 - v : v;
		v = ((r & 1) != (c & 1) ? w * 2 - 1 - r + c : r + c) % (w * 2);
		r = v >= w ? w * 2 - 1 - v : v;
		swap(val[l], val[r]);
	}
	vector<int> res(w);
	for (int i = 0; i < w; i++) {
		int v = (i & 1 ? w + (w - 1) - i + h : i + h) % (w * 2);
		res[val[i]] = v >= w ? w * 2 - 1 - v + 1 : v + 1;
	}
	for (int i = 0; i < w; i++) {
		cout << res[i] << endl;
	}
	return 0;
}