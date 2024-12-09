#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int n, m;
bool b[10];
bool graph[10][10];
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[b][a] = true;
		graph[a][b] = true;
	}
}
int dfs(int nn, int s) {
	if (nn == n)return 1;
	b[s] = true;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (graph[s][i] && !b[i])cnt += dfs(nn + 1, i);
	}
	b[s] = false;
	return cnt;
}
int main() {
	input();
	cout << dfs(1, 1) << endl;
	char c; cin >> c;
}