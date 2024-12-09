#include <bits/stdc++.h>
using namespace std;
const int mox = 1e5 + 9;
int tree[mox * 200][2];
int ra = 0;
int mn[mox * 200];
bool visit[mox];
int ri[mox];
void add(int x, int y) {
  int o = y;
  for (int i = 16; i >= 0; i--) {
    bool p = (x & (1 << i));
    if (tree[o][p] == 0) {
      tree[o][p] = ++ra;
    }
    o = tree[o][p];
    if (mn[o] == 0) {
      mn[o] = x;
    } else {
      mn[o] = min(mn[o], x);
    }
  }
}
int get(int x, int k, int s) {
  int o = k;
  int u = 0;
  for (int i = 16; i >= 0; i--) {
    bool p = ((1 << i) & x);
    if (mn[tree[o][!p]] <= (s - x) && mn[tree[o][!p]] != 0) {
      o = tree[o][!p];
      if (p == 0) u += (1 << i);
    } else if (mn[tree[o][p]] <= (s - x) && mn[tree[o][p]] != 0) {
      o = tree[o][p];
      if (p) u += (1 << i);
    } else {
      return -1;
    }
  }
  return u;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int a;
      cin >> a;
      if (visit[a] == 0) {
        for (int j = 1; (j * j) <= a; j++) {
          if ((a % j) == 0) {
            if (ri[j] == 0) {
              ri[j] = ++ra;
            }
            add(a, ri[j]);
            if (ri[(a / j)] == 0) {
              ri[(a / j)] = ++ra;
            }
            add(a, ri[(a / j)]);
          }
        }
        visit[a] = 1;
      }
    } else {
      int k, x, s;
      cin >> x >> k >> s;
      if (x % k) {
        cout << -1 << '\n';
      } else {
        if (ri[k] != 0)
          cout << get(x, ri[k], s) << '\n';
        else
          cout << -1 << '\n';
      }
    }
  }
}
