#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
int N, M, Q, out, query[400000][5];
bool reach[MAXN][MAXN], visited[MAXN];
vector<int> adj[MAXN];
int anc[MAXN + 1][12];
int compare_second(const void *first, const void *second) {
  const int *ia = (const int *)first;
  const int *ib = (const int *)second;
  return ia[1] - ib[1];
}
int compare_forth(const void *first, const void *second) {
  const int *ia = (const int *)first;
  const int *ib = (const int *)second;
  return ia[3] - ib[3];
}
void dfs(int start, int at) {
  if (reach[start][at]) return;
  reach[start][at] = true;
  for (int i : adj[at]) dfs(start, i);
}
void build(int at) {
  anc[N][0] = N;
  for (int i = 0; i < N; i++) {
    if (i == at)
      anc[i][0] = N;
    else {
      for (int j : adj[i]) {
        if (reach[j][at]) {
          anc[i][0] = j;
          break;
        }
      }
      if (adj[i].size() == 0) anc[i][0] = N;
    }
  }
  for (int k = 1; k < 12; k++)
    for (int i = 0; i < N + 1; i++) anc[i][k] = anc[anc[i][k - 1]][k - 1];
}
int jump(int at, int up) {
  for (int k = 0; k < 12; k++)
    if (up & (1 << k)) {
      at = anc[at][k];
    }
  return at;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> Q;
  for (int j = 0; j < M; j++) {
    int first, second;
    cin >> first >> second;
    first--;
    second--;
    adj[first].push_back(second);
  }
  for (int i = 0; i < N; i++) {
    sort(adj[i].begin(), adj[i].end());
    dfs(i, i);
  }
  for (int q = 0; q < Q; q++) {
    cin >> query[q][0] >> query[q][1] >> query[q][2];
    query[q][0]--;
    query[q][1]--;
    query[q][3] = q;
  }
  qsort(query, Q, 5 * sizeof(int), compare_second);
  for (int q = 0; q < Q; q++) {
    if (q == 0 || query[q][1] != query[q - 1][1]) build(query[q][1]);
    out = -1;
    if (reach[query[q][0]][query[q][1]] && jump(query[q][0], 3001) == N) {
      out = jump(query[q][0], query[q][2] - 1);
      if (out == N) out = -2;
      out++;
    }
    query[q][4] = out;
  }
  qsort(query, Q, 5 * sizeof(int), compare_forth);
  for (int q = 0; q < Q; q++) cout << query[q][4] << "\n";
}
