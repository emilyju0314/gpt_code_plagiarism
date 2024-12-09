#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n; string s;
int main() {
	while (cin >> n, n) {
		vector<string> l; vector<string> x(n); vector<vector<string> > g(n);
		for (int i = 0; i < n; i++) {
			cin >> s;
			int p = 0;
			for (int j = 1; j < s.size(); j++) {
				if (s[j] == ':' || s[j] == ',' || s[j] == '.') {
					string t = s.substr(p, j - p);
					if (p == 0) x[i] = t;
					else g[i].push_back(t);
					l.push_back(t);
					p = j + 1;
				}
			}
		}
		sort(l.begin(), l.end());
		l.erase(unique(l.begin(), l.end()), l.end());
		vector<vector<int> > G(l.size());
		for (int i = 0; i < n; i++) {
			int s = lower_bound(l.begin(), l.end(), x[i]) - l.begin();
			for (string j : g[i]) {
				int ptr = lower_bound(l.begin(), l.end(), j) - l.begin();
				G[s].push_back(ptr);
			}
		}
		int r = lower_bound(l.begin(), l.end(), x[0]) - l.begin();
		vector<bool> vis(l.size(), false); vis[r] = true;
		queue<int> que; que.push(r);
		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (int i : G[u]) {
				if (!vis[i]) {
					vis[i] = true;
					que.push(i);
				}
			}
		}
		int ret = 0;
		for (int i = 0; i < l.size(); i++) {
			if (vis[i] && G[i].size() == 0) ret++;
		}
		cout << ret << endl;
	}
	return 0;
}