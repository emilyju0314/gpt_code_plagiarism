#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
const int N = 100032;
using namespace std;

int a[N];
vector<int> e[N], que, buf;
bool vis[N];

void dfs(int x, int fa) {
	vis[x] = true;
	buf.push_back(a[x]);
	for (int u : e[x])
		if (u != fa) dfs(u,x);
}

int main() {
	int n, m, p = 0, u, v;
	scanf("%d%d",&n,&m);
	if (m == n-1) {puts("0"); return 0;}
	for (int i = 0; i < n; i++)
		scanf("%d",a+i);
	while (m--) {
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs(i,-1); p++;
		auto it = min_element(buf.begin(), buf.end());
		ans += *it;
		swap(*it, buf.back());
		que.insert(que.end(), buf.begin(), buf.end()-1);
		buf.clear();
	}
	auto l = que.begin(), r = l + p-2;
	if (r > que.end()) {puts("Impossible"); return 0;}
	nth_element(l, r, que.end());
	printf("%lld\n",accumulate(l, r, ans));
	return 0;
}
