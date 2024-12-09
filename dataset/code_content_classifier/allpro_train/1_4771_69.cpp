#include <bits/stdc++.h>
using namespace std;
template <class A>
void pr(A a) {
  cout << a;
  cout << '\n';
}
template <class A, class B>
void pr(A a, B b) {
  cout << a << ' ';
  pr(b);
}
template <class A, class B, class C>
void pr(A a, B b, C c) {
  cout << a << ' ';
  pr(b, c);
}
template <class A, class B, class C, class D>
void pr(A a, B b, C c, D d) {
  cout << a << ' ';
  pr(b, c, d);
}
template <class A>
void PR(A a, long long n) {
  for (long long i = (long long)(0); i < (long long)(n); i++) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}
long long check(long long n, long long m, long long x, long long y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}
const long long MAX = 1e9 + 7, MAXL = 1LL << 61, dx[4] = {-1, 0, 1, 0},
                dy[4] = {0, 1, 0, -1};
vector<pair<long long, long long> > v[222222];
long long mm[222222];
long long ans;
void dfs(int x, int p, int t) {
  queue<pair<long long, long long> > que;
  {
    int xx = x, yy = p;
    if (xx > yy) swap(xx, yy);
    long long w = -1;
    if (t != -1) w = mm[t];
    for (long long i = (long long)(1);
         i < (long long)(min((long long)v[x].size() + 2, ans + 1)); i++) {
      if (i == w) continue;
      que.push(pair<long long, long long>(0, i));
    }
    if (w != -1) que.push(pair<long long, long long>(1, w));
  }
  for (long long i = (long long)(0); i < (long long)(v[x].size()); i++) {
    int y = v[x][i].first;
    if (y == p) continue;
    pair<long long, long long> q = que.front();
    que.pop();
    int xx = y, yy = x;
    if (xx > yy) swap(xx, yy);
    mm[v[x][i].second] = q.second;
    q.first++;
    que.push(q);
  }
  while (!que.empty()) que.pop();
  for (long long i = (long long)(0); i < (long long)(v[x].size()); i++) {
    int y = v[x][i].first;
    if (y == p) continue;
    dfs(y, x, v[x][i].second);
  }
}
void Main() {
  memset(mm, -1, sizeof(mm));
  long long n, k;
  cin >> n >> k;
  long long c[n];
  memset(c, 0, sizeof(c));
  for (long long i = (long long)(0); i < (long long)(n - 1); i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (x > y) swap(x, y);
    v[x].push_back(pair<long long, long long>(y, i));
    v[y].push_back(pair<long long, long long>(x, i));
    c[x]++;
    c[y]++;
  }
  long long l = 0, r = n;
  while (l + 1 < r) {
    long long m = (l + r) / 2, cnt = 0;
    for (long long i = (long long)(0); i < (long long)(n); i++) {
      if (c[i] > m) cnt++;
    }
    if (cnt > k)
      l = m;
    else
      r = m;
  }
  ans = r;
  dfs(0, -1, -1);
  pr(ans);
  for (long long i = (long long)(0); i < (long long)(n - 1); i++) {
    if (i) cout << " ";
    cout << mm[i];
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Main();
  return 0;
}
