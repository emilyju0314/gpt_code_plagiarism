#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
struct fenwick_tree {
	vector<pair<int, int> > x;
	fenwick_tree(int n) : x(n, make_pair(0, 0)) { }
	pair<int,int> sum(int j) {
		pair<int,int> S = make_pair(0, 0);
		for (j; j >= 0; j = (j & (j + 1)) - 1) S = max(S, x[j]);
		return S;

	}
	void add(int k, pair<int,int> a) {
		for (; k < x.size(); k |= k + 1) x[k] = max(x[k], a);
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int,int> > A(N);
	fenwick_tree ft(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = -i;
	}

	sort(A.begin(), A.end());

	pair<int, int> res = make_pair(0, 0);
	for (int i = 0; i < N; i++) {
		int pos = -A[i].second;
		int val = A[i].first;
		pair<int, int> p = ft.sum(pos);

		p.first++;
		p.second += val;

		ft.add(pos, p);
		res = max(res, p);
	}



	cout << res.second << endl;
}
