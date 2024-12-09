#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	cin >> N; --N;
	vector<vector<int> > G(2 * N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int x;
			cin >> x;
			if (x == 1) {
				G[i].push_back(N + j);
				G[N + j].push_back(i);
			}
		}
	}
	vector<bool> vis, dec(2 * N, false);
	vector<int> match(2 * N, -1);
	function<bool(int)> find_augment = [&](int pos) {
		vis[pos] = true;
		for (int i : G[pos]) {
			if (!dec[i] && (match[i] == -1 || (!vis[match[i]] && find_augment(match[i])))) {
				match[i] = pos;
				match[pos] = i;
				return true;
			}
		}
		return false;
	};
	int cnt = 0;
	for (int i = 2 * N - 1; i >= N; --i) {
		vis = vector<bool>(2 * N, false);
		if (match[i] == -1 && find_augment(i)) {
			++cnt;
		}
	}
	if (cnt == N) {
		for (int i = N; i < 2 * N; ++i) {
			match[match[i]] = -1;
			match[i] = -1;
			vis = vector<bool>(2 * N, false);
			find_augment(i);
			dec[match[i]] = true;
		}
		cout << "yes" << endl;
		for (int i = 0; i < N; ++i) {
			cout << match[N + i] + 1 << '\n';
		}
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}
