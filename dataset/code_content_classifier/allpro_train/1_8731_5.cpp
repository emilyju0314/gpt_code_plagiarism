#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int perm_input(int K, vector<vector<int> > &perm) {
	vector<int> p(K);
	for (int i = 0; i < K; ++i) cin >> p[i], --p[i];
	return lower_bound(perm.begin(), perm.end(), p) - perm.begin();
}
int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<int> > perm;
	vector<int> pperm(K);
	for (int i = 0; i < K; ++i) pperm[i] = i;
	do {
		perm.push_back(pperm);
	} while (next_permutation(pperm.begin(), pperm.end()));
	vector<vector<int> > F(N, vector<int>(K));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			cin >> F[i][j];
		}
	}
	int fact = perm.size();
	vector<vector<int> > P(fact, vector<int>(N)), IP(fact, vector<int>(N));
	for (int i = 0; i < fact; ++i) {
		for (int j = 0; j < N; ++j) {
			P[i][j] = j;
		}
		sort(P[i].begin(), P[i].end(), [&](int x, int y) {
			for (int j = 0; j < K; ++j) {
				if (F[x][perm[i][j]] != F[y][perm[i][j]]) {
					return F[x][perm[i][j]] < F[y][perm[i][j]];
				}
			}
			return false;
			});
		for (int j = 0; j < N; ++j) {
			IP[i][P[i][j]] = j;
		}
	}
	int D;
	cin >> D;
	vector<vector<int> > G(N);
	vector<int> deg(N);
	for (int i = 0; i < D; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		++deg[b];
		G[a].push_back(b);
	}
	int cur = 0, pre = perm_input(K, perm), R;
	vector<int> ord(N + 1);
	cin >> R;
	for (int i = 0; i < R; ++i) {
		int tm, nxt;
		cin >> tm;
		nxt = perm_input(K, perm);
		for (int j = cur; j < tm; ++j) {
			ord[j] = pre;
		}
		cur = tm;
		pre = nxt;
	}
	for (int i = cur; i <= N; ++i) {
		ord[i] = pre;
	}
	vector<priority_queue<int> > que(fact);
	for (int i = 0; i < N; ++i) {
		if (deg[i] >= 1) continue;
		for (int j = 0; j < fact; ++j) {
			que[j].push(IP[j][i]);
		}
	}
	vector<bool> used(N, false);
	for (int i = 0; i < N; ++i) {
		int u = -1;
		while (u == -1 || used[u]) {
			u = P[ord[i]][que[ord[i]].top()];
			que[ord[i]].pop();
		}
		used[u] = true;
		cout << u + 1 << '\n';
		for (int j : G[u]) {
			--deg[j];
			if (deg[j] == 0) {
				for (int k = 0; k < fact; ++k) {
					que[k].push(IP[k][j]);
				}
			}
		}
	}
	return 0;
}
