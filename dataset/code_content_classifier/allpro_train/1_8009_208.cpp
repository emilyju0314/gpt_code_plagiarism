#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> adj[500001];
int depth[500001];
char A[500001];
vector<int> sub[500001];
bool ans[500001];
vector<pair<int, int> > query[500001];
void DFS(int u, int p) {
  depth[u] = depth[p] + 1;
  int best = 0, bestid = 0;
  for (int v : adj[u]) {
    DFS(v, u);
    if (sub[v].size() > best) {
      best = sub[v].size();
      bestid = v;
    }
  }
  swap(sub[bestid], sub[u]);
  for (int v : adj[u]) {
    if (v == bestid) continue;
    for (int i = sub[u].size() - 1, j = sub[v].size() - 1; j >= 0; i--, j--) {
      sub[u][i] ^= sub[v][j];
    }
    sub[v].clear();
  }
  sub[u].push_back((1 << A[u]));
  for (pair<int, int> now : query[u]) {
    if (now.first < depth[u] || now.first > depth[u] + sub[u].size() - 1) {
      ans[now.second] = 1;
    } else {
      ans[now.second] =
          (__builtin_popcount(
               sub[u][sub[u].size() - (now.first - depth[u]) - 1]) < 2
               ? 1
               : 0);
    }
  }
  return;
}
int main() {
  scanf("%d %d", &N, &M);
  int u, h;
  for (int i = 2; i <= N; i++) {
    scanf("%d", &u);
    adj[u].push_back(i);
  }
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    A[i] = A[i] - (int)'a';
  }
  for (int i = 1; i <= M; i++) {
    scanf("%d %d", &u, &h);
    query[u].push_back({h, i});
  }
  DFS(1, 0);
  for (int i = 1; i <= M; i++) {
    if (ans[i] == 1)
      puts("Yes");
    else
      puts("No");
  }
}
