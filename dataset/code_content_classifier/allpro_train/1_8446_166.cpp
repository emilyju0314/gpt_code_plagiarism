#include <bits/stdc++.h>
using namespace std;
const long long lINF = 1e18;
const long long INF = 1e18;
const double EPS = 1e-12;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
int myrand() { return rand(); }
int rnd(int x) { return myrand() % x; }
const int maxn = (int)1e5 + 100;
int a[maxn], n;
vector<int> tree[maxn];
long long dp1[maxn], dp2[maxn];
bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    tree[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  return true;
}
pair<long long, long long> add(pair<long long, long long> a, long long b) {
  if (b > a.first) {
    a.second = a.first;
    a.first = b;
  } else {
    if (b > a.second) {
      a.second = b;
    }
  }
  return a;
}
pair<long long, long long> join(pair<long long, long long> a,
                                pair<long long, long long> b) {
  return add(add(a, b.first), b.second);
}
void getmx(int v, int par = -1) {
  long long &ans1 = dp1[v], &ans2 = dp2[v];
  ans1 = 0, ans2 = 0;
  pair<long long, long long> mxs(0, 0);
  for (int i = 0; i < ((int)((tree[v]).size())); i++) {
    int to = tree[v][i];
    if (to == par) {
      continue;
    }
    getmx(to, v);
    ans1 = max(ans1, dp1[to]);
    mxs = add(mxs, dp1[to]);
  }
  ans1 += a[v];
  ans2 = max(mxs.first + mxs.second + a[v], ans1);
}
long long ans;
void solve(int v, int par = -1, long long up1 = 0, long long up2 = 0) {
  ans = max(ans, up2 + dp2[v]);
  int m = ((int)((tree[v]).size()));
  vector<long long> pref2(m + 1, 0), suf2(m + 1, 0);
  vector<pair<long long, long long> > pref1(m + 1, make_pair(0, 0)),
      suf1(m + 1, make_pair(0, 0));
  for (int i = 0; i < m; i++) {
    if (tree[v][i] == par) {
      pref1[i + 1] = pref1[i];
      pref2[i + 1] = pref2[i];
      continue;
    }
    pref1[i + 1] = add(pref1[i], dp1[tree[v][i]]);
    pref2[i + 1] = max(pref2[i], dp2[tree[v][i]]);
  }
  for (int i = m - 1; i >= 0; i--) {
    if (tree[v][i] == par) {
      suf1[i] = suf1[i + 1];
      suf2[i] = suf2[i + 1];
      continue;
    }
    suf1[i] = add(suf1[i + 1], dp1[tree[v][i]]);
    suf2[i] = max(suf2[i + 1], dp2[tree[v][i]]);
  }
  for (int i = 0; i < m; i++) {
    if (tree[v][i] == par) {
      continue;
    }
    long long nup2 = up2;
    nup2 = max(nup2, pref2[i]);
    nup2 = max(nup2, suf2[i + 1]);
    pair<long long, long long> mxs = join(pref1[i], suf1[i + 1]);
    mxs = add(mxs, up1);
    nup2 = max(nup2, mxs.first + mxs.second + a[v]);
    solve(tree[v][i], v,
          max(up1, max(pref1[i].first, suf1[i + 1].first)) + a[v], nup2);
  }
}
int used[maxn];
bool ok;
long long mkill(int from, int to, int par = -1) {
  if (from == to) {
    if (used[from]) {
      ok = false;
    }
    used[from] = 1;
    return a[from];
  }
  for (int i = 0; i < ((int)((tree[from]).size())); i++) {
    int u = tree[from][i];
    if (u == par) {
      continue;
    }
    long long res = mkill(u, to, from);
    if (res >= 0) {
      if (used[from]) {
        ok = false;
      }
      used[from] = 1;
      return res + a[from];
    }
  }
  return -1;
}
void solve() {
  ans = 0;
  for (int i = 0; i < 5; i++) {
    int v = rnd(n);
    getmx(v);
    solve(v);
  }
  printf(
      "%lld"
      "\n",
      ans);
}
int main() {
  srand(rdtsc());
  while (true) {
    if (!read()) {
      break;
    }
    solve();
  }
  return 0;
}
