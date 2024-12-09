#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int m, n;
pii a[100001];
vector<int> adj[100001];
bool is_chosen[100001];
bool is_visited[100001];
int cnt = 0;
template <typename T>
inline T read() {
  T x = 0;
  T multiplier = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      multiplier = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch & 15);
    ch = getchar();
  }
  return x * multiplier;
}
void dfs(int u, int prt) {
  if (is_chosen[a[u].first] && is_chosen[a[u].second]) {
    return;
  }
  if (is_visited[u]) {
    return;
  }
  is_visited[u] = true;
  bool x = is_chosen[a[u].first], y = is_chosen[a[u].second];
  if (!x) {
    is_chosen[a[u].first] = true;
    is_chosen[a[u].second] = true;
    for (auto v : adj[a[u].first]) {
      if (v != prt) {
        dfs(v, u);
      }
    }
  }
  if (!y) {
    is_chosen[a[u].first] = true;
    is_chosen[a[u].second] = true;
    for (auto v : adj[a[u].second]) {
      if (v != prt) {
        dfs(v, u);
      }
    }
  }
  is_chosen[a[u].first] = true;
  is_chosen[a[u].second] = true;
}
int main() {
  n = read<int>(), m = read<int>();
  for (int i = 1; i <= m; i++) {
    a[i].first = read<int>();
    a[i].second = read<int>();
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; i++) {
    adj[a[i].first].push_back(i);
    adj[a[i].second].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    if (!is_visited[i]) {
      dfs(i, -1);
    }
  }
  for (int i = 1; i <= m; i++) {
    cnt += !is_visited[i];
  }
  printf("%d\n", cnt);
  return 0;
}
