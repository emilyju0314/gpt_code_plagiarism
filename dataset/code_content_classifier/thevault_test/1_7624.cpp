int func(int id, int len, int root, int goal_len) {
	if (len > goal_len) {
		return INF;
	} else if (len == goal_len) {
		if (id == root) {
			return 0;
		} else {
			return INF;
		}
	} else {
		int& ans = dp[id][len];

		if (ans == -1) {
			ans = INF;

			for (int i = 0; i < (int) graph[id].size(); i++) {
				int u = graph[id][i].first;
				int f = graph[id][i].second;

				chmin(ans, f + func(u, len + 1, root, goal_len));
			}
		}

		return ans;
	}
}