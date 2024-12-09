#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
std::pair<int, int> d[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
	int h = ri(), w = ri(), k = ri();
	std::string a[h];
	for (auto &i : a) std::cin >> i;
	int gx, gy, sx, sy;
	std::vector<std::pair<int, int> > apples;
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
		if (a[i][j] == 's') sx = i, sy = j;
		if (a[i][j] == 'e') gx = i, gy = j;
		if (a[i][j] == 'a') apples.push_back({i, j});
	}
	apples.push_back({gx, gy});
	apples.push_back({sx, sy});
	int m = apples.size();
	int dist[m][m];
	for (int i = 0; i < m; i++) {
		int distt[h][w];
		for (int j = 0; j < h; j++) for (int k = 0; k < w; k++) distt[j][k] = 1000000000;
		std::queue<std::pair<int, int> > que;
		que.push(apples[i]);
		distt[apples[i].first][apples[i].second] = 0;
		while (que.size()) {
			auto cur = que.front();
			que.pop();
			for (auto dd : d) {
				int new_x = cur.first + dd.first;
				int new_y = cur.second + dd.second;
				if (new_x < 0 || new_x >= h) continue;
				if (new_y < 0 || new_y >= w) continue;
				if (a[new_x][new_y] == '#') continue;
				if (distt[new_x][new_y] > distt[cur.first][cur.second] + 1) {
					distt[new_x][new_y] = distt[cur.first][cur.second] + 1;
					que.push({new_x, new_y});
				}
			}
		}
		
		for (int j = 0; j < m; j++) {
			dist[i][j] = distt[apples[j].first][apples[j].second];
		}
	}
	m -= 2;
	std::vector<std::vector<int> > dp(1 << m, std::vector<int>(m, 1000000000));
	for (int i = 0; i < m; i++) {
		dp[1 << i][i] = dist[i][m + 1];
	}
	for (int i = 0; i < 1 << m; i++) {
		for (int j = 0; j < m; j++) {
			if (dp[i][j] == 1000000000) continue;
			for (int k = 0; k < m; k++) {
				if (i >> k & 1) continue;
				dp[i | 1 << k][k] = std::min(dp[i | 1 << k][k], dp[i][j] + dist[j][k]);
			}
		}
	}
	int min = 1000000000;
	for (int i = 0; i < 1 << m; i++) {
		if (__builtin_popcount(i) < k) continue;
		for (int j = 0; j < m; j++) {
			min = std::min(min, dp[i][j] + dist[j][m]);
		}
	}
	std::cout << (min == 1000000000 ? -1 : min) << std::endl;
	return 0;
}


