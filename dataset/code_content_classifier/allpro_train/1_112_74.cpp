#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double tau = 2 * pi;
const double epsilon = 1e-9;
const int MAX_N = 100100;
int N, SB;
int nxt[MAX_N];
int prv[MAX_N];
vector<int> cc;
bool vis[MAX_N];
int dfs(int u) {
  if (vis[u]) return 0;
  vis[u] = true;
  if (u == SB)
    return -(1 << 30) + dfs(nxt[u]) + dfs(prv[u]);
  else
    return 1 + dfs(nxt[u]) + dfs(prv[u]);
}
bool sum[MAX_N];
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> N >> SB;
  for (int i = 1; i <= N; i++) {
    int tmp;
    cin >> tmp;
    nxt[i] = tmp;
    prv[tmp] = i;
  }
  vis[0] = true;
  for (int i = 1; i <= N; i++) {
    int ccsz = dfs(i);
    if (ccsz > 0) cc.push_back(ccsz);
  }
  int SBpos = 0, cur = SB;
  while (cur != 0) {
    cur = nxt[cur];
    ++SBpos;
  }
  sum[0] = true;
  for (int i = 0; i < ((int)cc.size()); i++)
    for (int j = MAX_N - 1; j >= 0; j--)
      if (sum[j] && (j + cc[i] < MAX_N)) sum[j + cc[i]] = true;
  for (int i = 0; i < MAX_N; i++)
    if (sum[i] && (i + SBpos <= N)) cout << i + SBpos << '\n';
  return 0;
}
