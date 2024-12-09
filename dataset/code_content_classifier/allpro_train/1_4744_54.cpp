#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, a[N], pa[N], dep[N], deg[N], vis[N], bot[N], blue[N], black[N];
vector<int> ans;
inline void Rot(int u) {
	ans.push_back(u);
	int t = a[u];
	a[u] = a[0];
	for (u = pa[u]; u >= 0; swap(t, a[u]), u = pa[u]);
}
vector<int> lf;
int main() {
	scanf("%d", &n);
	pa[0] = -1;
	dep[0] = 0;
	for (int i = 1; i < n; i++) {
		scanf("%d", &pa[i]);
		dep[i] = dep[pa[i]] + 1;
		deg[pa[i]]++;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		vis[i] = 0;
	}
	while (true) {
		lf.clear();
		memset(black, 0, sizeof(black));
		for (int i = n - 1; i >= 0; i--) if (!vis[i] && !deg[i]) {
			lf.push_back(i);
			vis[i] = 1;
			bot[i] = i;
			int u = pa[i];
			while (u >= 0 && deg[u] == 1) {
				lf.push_back(u);
				vis[u] = 1;
				bot[u] = i;
				u = pa[u];
			}
		}
		if (lf.empty()) break;
		int cur = lf.size();
		while (cur) {
			if (vis[a[0]]) {
				cur--;
				int u = bot[a[0]];
				while (true) {
					if (!blue[u] || a[u] < a[0]) break;
					u = pa[u];
				}
				Rot(u);
				while (blue[u]) u = pa[u];
				blue[u] = 1;
			} else {
				int mxdep = -1, u = -1;
				for (int i = 0; i < n; i++) {
					if (!blue[i] && !black[a[i]]) {
						if (mxdep < dep[i]) {
							mxdep = dep[i];
							u = i;
						}
					}
				}
				black[a[0]] = 1;
				Rot(u);
			}
		}
		for (int u : lf) {
			if (u > 0) deg[pa[u]]--;
		}
	}
	printf("%d\n", (int)ans.size());
	for (int x : ans) printf("%d\n", x);
	return 0;
}