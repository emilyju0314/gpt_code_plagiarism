#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
vector<long long> in_seg;
vector<long long> seg;
vector<long long> used;
vector<long long> level;
long long t = -1;
inline long long addMod(long long a, long long b) {
  a += b;
  a += mod * mod + mod;
  a %= mod;
  return a;
}
inline long long mulMod(long long a, long long b) {
  return ((long long)a * b + mod * mod + mod) % mod;
}
void dfs(vector<vector<long long> > &g, long long v, long long p,
         long long dep) {
  level[v] = dep;
  t++;
  long long t_beg = t;
  in_seg[v] = t;
  for (long long i = 0; i < (long long)g[v].size(); i++)
    if (g[v][i] != p) dfs(g, g[v][i], v, dep + 1);
  seg[t_beg] = t;
}
long long pow1 = 1 << 21, pow2 = 1 << 22;
struct st {
  vector<long long> sg;
  vector<long long> add_arr;
  st() {
    sg.assign(pow2, 0);
    add_arr.assign(pow2, 0);
  }
  void add(long long v, long long l, long long r, long long L, long long R,
           long long val) {
    if (l > r) return;
    long long M = (L + R) / 2;
    if (l == L && r == R) {
      add_arr[v] = addMod(add_arr[v], val);
      return;
    }
    add(2 * v, l, min(M, r), L, M, val);
    add(2 * v + 1, max(M + 1, l), r, M + 1, R, val);
  }
  long long get(long long v) {
    long long sum = 0;
    v += pow1;
    while (v) {
      sum = addMod(sum, add_arr[v]);
      v >>= 1;
    }
    return sum;
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, p;
  cin >> n;
  vector<vector<long long> > g(n);
  for (long long i = 1; i < n; i++) {
    cin >> p;
    p--;
    g[p].push_back(i);
  }
  seg.resize(n);
  in_seg.resize(n);
  used.assign(n, 0);
  level.assign(n, 0);
  dfs(g, 0, -1, 0);
  long long m;
  cin >> m;
  long long type;
  st t1, t2;
  for (long long i = 0; i < m; i++) {
    cin >> type;
    if (type == 1) {
      long long v, x, k;
      cin >> v >> x >> k;
      v--;
      long long beg = in_seg[v];
      long long en = seg[beg];
      long long add_val = x + level[v] * k;
      t1.add(1, beg, en, 0, pow1 - 1, add_val);
      t2.add(1, beg, en, 0, pow1 - 1, k);
    } else {
      long long v;
      cin >> v;
      v--;
      long long ord_v = in_seg[v];
      long long res = addMod(t1.get(ord_v), -mulMod(t2.get(ord_v), level[v]));
      cout << (res + mod * mod) % mod << '\n';
    }
  }
  return 0;
}
