#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
int n, cnt;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch & 15);
    ch = getchar();
  }
  return x * f;
}
struct ufs {
  int f[N];
  void init() {
    for (int i = 1; i <= n; ++i) f[i] = i;
  }
  int find(int x) { return f[x] ^ x ? f[x] = find(f[x]) : x; }
} s;
bitset<N> neighbors[N], d1[N], notLeaf;
void add(int u, int v) {
  int fu = s.find(u), fv = s.find(v);
  if (fu ^ fv) {
    cout << u << ' ' << v << endl;
    ++cnt;
    s.f[fu] = fv;
    d1[u].set(v, 1), d1[u].set(u, 1);
    d1[v].set(u, 1), d1[v].set(v, 1);
    notLeaf[u] = notLeaf[v] = 1;
  }
}
int main() {
  n = read();
  if (n == 2) return puts("1 2"), 0;
  for (int i = 1; i <= n; ++i) {
    int k = read();
    while (k--) neighbors[i].set(read(), 1);
  }
  s.init();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      bitset<N> tmp = neighbors[i] & neighbors[j];
      if (tmp.count() == 2) {
        int u = 0, v = 0;
        for (int k = 1; k <= n; ++k) {
          if (tmp[k]) {
            if (u)
              v = k;
            else
              u = k;
          }
        }
        add(u, v);
      }
    }
  }
  if (cnt == 0) {
    for (int i = 2; i <= n; ++i) {
      cout << 1 << ' ' << i << endl;
    }
    return 0;
  }
  if (cnt == 1) {
    int u = 0, v = 0;
    for (int i = 1; i <= n; ++i) {
      if (notLeaf[i]) {
        if (u)
          v = i;
        else
          u = i;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (neighbors[i].count() != n) {
        for (int j = 1; j <= n; ++j) {
          if (j != u && j != v) {
            cout << (neighbors[i][j] ? u : v) << ' ' << j << endl;
          }
        }
        break;
      }
    }
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (notLeaf[i]) continue;
    int mn = 1e9;
    bitset<N> tmp;
    for (int j = 1; j <= n; ++j) {
      if (neighbors[j][i] && (neighbors[j] & notLeaf).count() < mn) {
        tmp = neighbors[j] & notLeaf;
        mn = tmp.count();
      }
    }
    for (int j = 1; j <= n; ++j) {
      if (tmp[j] && d1[j] == tmp) {
        cout << i << ' ' << j << endl;
        break;
      }
    }
  }
  return 0;
}
