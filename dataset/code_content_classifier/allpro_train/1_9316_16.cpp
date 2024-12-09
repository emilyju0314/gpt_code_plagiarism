#include <bits/stdc++.h>
using namespace std;
struct aho {
  const int AL = 26;
  int n;
  vector<vector<int> > g;
  vector<int> link;
  vector<long long> cost;
  aho(vector<string> s, vector<int> a) {
    n = 1;
    g.assign(1, vector<int>(AL, -1));
    link.assign(1, 0);
    cost.assign(1, 0);
    for (int i = 0; i < (int)((s).size()); i++) {
      string t = s[i];
      int v = 0;
      for (char c : t) {
        c -= 'a';
        if (g[v][c] == -1) {
          g.push_back(vector<int>(AL, -1));
          link.push_back(-1);
          cost.push_back(0);
          g[v][c] = n++;
        }
        v = g[v][c];
      }
      cost[v] += a[i];
    }
    queue<int> q;
    q.push(0);
    vector<int> used(n, 0);
    while (q.size()) {
      int v = q.front();
      used[v] = 1;
      q.pop();
      for (int i = 0; i < (int)((g[v]).size()); i++) {
        int &u = g[v][i];
        if (u == -1) {
          if (v == 0) {
            u = 0;
          } else {
            u = g[link[v]][i];
          }
        } else if (!used[u]) {
          if (v == 0) {
            link[u] = 0;
          } else {
            link[u] = g[link[v]][i];
          }
          q.push(u);
        }
        used[u] = 1;
      }
    }
    vector<long long> cost1 = cost;
    for (int i = 0; i < n; i++) {
      int v = i;
      while (v) {
        v = link[v];
        cost1[i] += cost[v];
      }
    }
    cost = cost1;
  }
};
const long long INF = -1e18;
vector<vector<long long> > prod(vector<vector<long long> > a,
                                vector<vector<long long> > b) {
  int n = (int)((a).size());
  vector<vector<long long> > c(n, vector<long long>(n, -1));
  for (int i = 0; i < n; i++) {
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (a[i][k] >= 0 && b[k][j] >= 0) {
          c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
        }
      }
    }
  }
  return c;
}
vector<vector<long long> > binpow(vector<vector<long long> > mtr, long long y) {
  if (y == 1) {
    return mtr;
  }
  if (y % 2) {
    return prod(binpow(mtr, y - 1), mtr);
  }
  return binpow(prod(mtr, mtr), y / 2);
}
int solve() {
  ios::sync_with_stdio(0);
  int n;
  if (!(cin >> n)) {
    return 1;
  }
  long long l;
  cin >> l;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  vector<string> s(n);
  for (string &t : s) {
    cin >> t;
  }
  aho corasic(s, a);
  vector<vector<long long> > mtr(corasic.n, vector<long long>(corasic.n, -1));
  for (int i : corasic.cost) {
  }
  for (int i = 0; i < corasic.n; i++) {
    for (int u : corasic.g[i]) {
      mtr[i][u] = max(corasic.cost[u], mtr[i][u]);
    }
  }
  mtr = binpow(mtr, l);
  long long ans = 0;
  for (long long i : mtr[0]) {
    ans = max(ans, i);
  }
  cout << ans << endl;
  return 0;
}
int32_t main() {
  int T = 1;
  for (int i = 1;; i++) {
    if (solve()) break;
  }
  return 0;
}
