#include <bits/stdc++.h>
using namespace std;
const int Z = (int)3e5 + 1;
int nxt[Z * 30 - 1000][2], cnt[Z * 30 - 1000];
int a[Z], p[Z], len = 1;
void add(int x, int delta) {
  for (int i = 29, v = 1; i >= 0; --i) {
    int bit = (x >> i & 1);
    if (!nxt[v][bit]) {
      nxt[v][bit] = ++len;
    }
    v = nxt[v][bit];
    cnt[v] += delta;
  }
}
int get(int x) {
  int res = 0;
  for (int i = 29, v = 1; i >= 0; --i) {
    res *= 2;
    int bit = (x >> i & 1);
    if (!cnt[nxt[v][bit]]) {
      res++;
      v = nxt[v][bit ^ 1];
    } else {
      v = nxt[v][bit];
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    add(p[i], 1);
  }
  for (int i = 1; i <= n; ++i) {
    int res = get(a[i]);
    cout << res << ' ';
    add(res ^ a[i], -1);
  }
  return 0;
}
