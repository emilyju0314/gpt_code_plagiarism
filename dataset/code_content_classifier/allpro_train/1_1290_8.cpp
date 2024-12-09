#include <bits/stdc++.h>

const int N = 100005;
int head[N], tot;
struct edge { int to, nxt; } e[N << 1];
void link(int x, int y) {
	e[++tot] = (edge) { y, head[x] }, head[x] = tot;
	e[++tot] = (edge) { x, head[y] }, head[y] = tot;
}

bool dfs(int x, int f = 0) {
	int sum = 0;
	for (int i = head[x]; i; i = e[i].nxt)
		if (e[i].to != f) sum += dfs(e[i].to, x);
	if (sum > 1) std::cout << "First\n", std::exit(0);
	return !sum;
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	int n; std::cin >> n;
	for (int i = 1, x, y; i < n; ++i)
		std::cin >> x >> y, link(x, y);
	std::cout << (dfs(1) ? "First" : "Second") << '\n';
	return 0;
}