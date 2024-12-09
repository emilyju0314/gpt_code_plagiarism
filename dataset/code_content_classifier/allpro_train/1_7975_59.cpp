#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, w = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') w = 0, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return w ? x : -x;
}
const int N = 1e5 + 5;
const int M = 1e7 + 5;
int mrk[M], mu[M], sum[M], n, m, k, id[N];
vector<int> pri, fac[N], S, T, adj[N];
void add(int x) {
  for (int d : fac[x]) ++sum[d];
}
void clear(int x) {
  for (int d : fac[x]) sum[d] = 0;
}
int query(int x) {
  int res = 0;
  for (int d : fac[x]) res += sum[d] * mu[d];
  return res;
}
void solve(int l, int r, vector<int> q) {
  if (!q.size()) return;
  if (l == r) {
    adj[l] = q;
    return;
  }
  int mid = l + r >> 1;
  vector<int> foo, bar;
  for (int i = l; i <= mid; ++i) add(S[i]);
  for (int i : q)
    if (query(i))
      foo.push_back(i);
    else
      bar.push_back(i);
  for (int i = l; i <= mid; ++i) clear(S[i]);
  solve(l, mid, foo);
  solve(mid + 1, r, bar);
}
bool cmp(int i, int j) { return adj[i].size() > adj[j].size(); }
int main() {
  mu[1] = 1;
  for (int i = 2; i < M; ++i) {
    if (!mrk[i]) pri.push_back(i), mu[i] = -1;
    for (int p : pri) {
      if (i * p >= M) break;
      mrk[i * p] = 1;
      if (i % p)
        mu[i * p] = -mu[i];
      else
        break;
    }
  }
  n = gi();
  k = gi();
  for (int i = 1; i <= n; ++i) {
    int a = gi();
    vector<int> tmp;
    for (int p : pri) {
      if (p * p > a) break;
      if (a % p == 0) {
        tmp.push_back(p);
        while (a % p == 0) a /= p;
      }
    }
    if (a > 1) tmp.push_back(a);
    int sz = tmp.size();
    for (int j = 0; j < 1 << sz; ++j) {
      int d = 1;
      for (int k = 0; k < sz; ++k)
        if (j >> k & 1) d *= tmp[k];
      fac[i].push_back(d);
    }
  }
  for (int i = 1; i <= n; ++i)
    if (query(i))
      T.push_back(i);
    else
      add(i), S.push_back(i);
  m = S.size();
  if (m >= k) {
    for (int i = 0; i < k; ++i) printf("%d ", S[i]);
    return puts(""), 0;
  }
  for (int i : S) clear(i);
  solve(0, m - 1, T);
  for (int i = 0; i < m; ++i) id[i] = i;
  sort(id, id + m, cmp);
  for (int i = 0, s = 0; i < m; ++i) {
    s += adj[id[i]].size() + 1;
    if (s >= k) {
      int tmp = k - (i + 1) * 2;
      for (int j = 0; j <= i; ++j) {
        int t = min((int)adj[id[j]].size() - 1, tmp);
        tmp -= t;
        printf("%d ", S[id[j]]);
        for (int x = 0; x <= t; ++x) printf("%d ", adj[id[j]][x]);
      }
      return puts(""), 0;
    }
  }
}
