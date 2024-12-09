#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_N = 300;
int n;
int w[MAX_N];
int memo[MAX_N][MAX_N + 1];

int dfs(const int l, const int r) {
	if(l >= r) return 0;
	int &res = memo[l][r];
	if(res != -1) return res;

	res = dfs(l + 1, r);
	for(int i = l + 1; i < r; i += 2) {
		const int width = i - l - 1;
		if(abs(w[l] - w[i]) <= 1 && dfs(l + 1, i) == width) {
			res = max(res, dfs(i + 1, r) + width + 2);
		}
	}
	return res;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	while(cin >> n && n) {
		for(int i = 0; i < n; ++i) {
			cin >> w[i];
		}
		memset(memo, -1, sizeof(memo));
		cout << dfs(0, n) << endl;
	}
	return EXIT_SUCCESS;
}