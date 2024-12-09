#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e5 + 5;

int n, m;
vector <int> adj[N];
int col[N];
ll cnt[3];
bool val;

void dfs(int v) {
	for (auto u : adj[v]) {
		if(!col[u]) {
			col[u] = 3 - col[v];
			dfs(u);
		}
		else if(col[u] == col[v])
			val = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {
		if(!col[i]) {
			if(adj[i].size() == 0)
				cnt[0]++;
			else {
				col[i] = val = 1;
				dfs(i);
				if(val)
					cnt[1]++;
				else
					cnt[2]++;
			}
		}
	}
//	cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << "\n";
	cout << 1LL * (2 * n - cnt[0]) * cnt[0] + 1LL * (cnt[1] + cnt[2]) * (cnt[1] + cnt[2]) + (cnt[1] * cnt[1]) << "\n";
}
