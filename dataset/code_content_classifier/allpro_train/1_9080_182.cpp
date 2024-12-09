#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ice(90, vector<int>(90));

int m, n;

const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {-1, 0, 0, 1};

int dfs(int i, int j, int count) {
	if (i < 0 || n <= i || j < 0 || m <= j || ice[i][j] == 0) return 0;
	ice[i][j] = 0;
	int ret = count;
	for (int k=0; k<4; ++k) {
		ret = max(ret, dfs(i + dy[k], j + dx[k], count + 1));
	}
	ice[i][j] = 1;
	return ret;
}

int main() {
	while (cin >> m >> n && m && n) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				cin >> ice[i][j];
			}
		}
		int ans = 0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				ans = max(ans, dfs(i, j, 1));
			}
		}
		cout << ans << endl;
	}
	return 0;
}