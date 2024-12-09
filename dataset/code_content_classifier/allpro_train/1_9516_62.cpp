#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n;
int cost[20][20];
int edgenum[20];
int dis[20];//?????????????????????????????§??????????????¢????????????????????????

void dfs(int idx,int totalcost,int parent) {
	if (edgenum[idx] == 1) {
		dis[idx] = -1;
		return;
	}
	dis[idx] = totalcost;
	for (int i = 0; i < n; i++) {
		if (cost[idx][i] > 0 && i != parent) {
			dfs(i, totalcost + cost[idx][i], idx);
		}
	}
}

int main() {
	while (cin >> n, n) {
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			cost[a - 1][b - 1] = cost[b - 1][a - 1] = c;
			ans += (c * 2);
		}
		for (int i = 1; i < n; i++) {
			int ct = 0, idx = 0;
			for (int j = 0; j < n; j++) {
				if (cost[i][j] > 0)ct++, idx = j;
			}
			edgenum[i] = ct;
			if (ct == 1) {
				ans -= (cost[i][idx] * 2);
			}
		}
		dfs(0, 0, -1);
		int biggest = 0;
		for (int i = 0; i < n; i++) {
			biggest = std::max(biggest, dis[i]);
		}
		std::cout << ans - biggest << std::endl;
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cost[i][j] = 0;
		for (int i = 0; i < n; i++)dis[i] = 0;
		for (int i = 0; i < n; i++)edgenum[i] = 0;
	}
	return 0;
}