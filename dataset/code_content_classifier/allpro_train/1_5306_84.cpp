#include<bits/stdc++.h>
using namespace std;
#define int int64_t
void solve() {
		int N; cin >> N;
		vector<vector<int>> grid(N, vector<int> (N, 0));
		for (int i = 0; i < N; ++i) {
			int p; cin >> p;
			grid[i][i] = p;
		}
		for (int i = 0; i < N; ++i) {
			int cnt = grid[i][i] - 1;
			int x = i, y = i;
			while (cnt) { 
				int cntt = 0;
				if (y+1 < i && grid[x][y+1] == 0) {
					grid[x][++y] = grid[i][i]; ++cntt;
				} else if (x-1 >= 0 && y < i && grid[x-1][y] == 0) {
					grid[--x][y] = grid[i][i]; ++cntt;
				} else if (y-1 >= 0 && grid[x][y-1] == 0) {
					grid[x][--y] = grid[i][i]; ++cntt;
				}
				if (cntt > 0) cnt -= cntt; else break;
			}
			while (cnt) { 
				int cntt = 0;
				if (y-1 >= 0 && grid[x][y-1] == 0) {
					grid[x][--y] = grid[i][i]; ++cntt;
				} else if (x+1 < N && grid[x+1][y] == 0) {
					grid[++x][y] = grid[i][i]; ++cntt;
				} else if (y+1 < N && grid[x][y+1] == 0) {
					grid[x][++y] = grid[i][i]; ++cntt;
				}
				if (cntt > 0) cnt -= cntt; else break;
			}
			
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j) cout << grid[i][j] << " "; cout << endl;
		}
	return;
}
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
		int T; T = 1; for (int t = 1; t <= T; ++t) solve();
	return 0;
}