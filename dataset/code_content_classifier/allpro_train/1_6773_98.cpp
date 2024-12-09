#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  T sum = 0, sign = 1;
  char c = getchar();
  while (!((c) >= '0' && (c) <= '9')) {
    if (c == '-') sign = -1;
    c = getchar();
  }
  while (((c) >= '0' && (c) <= '9')) {
    sum = (sum << 1) + (sum << 3) + c - '0';
    c = getchar();
  }
  x = sum * sign;
}
template <typename T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
const int N = 2e5 + 50;
struct Trie {
  int tr[N * 30][2], cnt = 0, size[N * 30], f[N * 30];
  inline void insert(int x) {
    int u = 0;
    for (int i = 30; i >= 0; --i) {
      int p = x >> i & 1;
      ++size[u];
      if (!tr[u][p]) tr[u][p] = ++cnt;
      u = tr[u][p];
    }
    ++size[u];
  }
  inline void dfs(int u) {
    int l = tr[u][0], r = tr[u][1];
    if (!l && !r) return;
    if (!r) {
      dfs(l), f[u] = f[l];
      return;
    }
    if (!l) {
      dfs(r), f[u] = f[r];
      return;
    }
    dfs(l), dfs(r);
    f[u] = min(f[l] + size[r] - 1, f[r] + size[l] - 1);
  }
} trie;
inline void solve() {
  int n;
  read(n);
  for (int x, i = 1; i <= n; ++i) read(x), trie.insert(x);
  trie.dfs(0);
  printf("%d\n", trie.f[0]);
}
int test;
int main() {
  test = 1;
  for (int i = 1; i <= test; ++i) solve();
  return 0;
}
