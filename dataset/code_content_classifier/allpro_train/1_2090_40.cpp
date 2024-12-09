#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
int m, n;
pair<int, int> a[N];
pair<int, int> b[N];
long long pat;
int answ[N];
pair<long long, int> t[4 * N];
long long d[4 * N];
void build(int v, int s, int e) {
  if (s == e) {
    t[v].second = s;
    t[v].first = 0;
    return;
  }
  int m = (s + e) / 2;
  build(2 * v, s, m);
  build(2 * v + 1, m + 1, e);
  t[v] = min(t[2 * v], t[2 * v + 1]);
}
void push(int v, int s, int e) {
  if (d[v] == 0) return;
  t[v].first += d[v];
  if (s != e) {
    d[2 * v] += d[v];
    d[2 * v + 1] += d[v];
  }
  d[v] = 0;
}
void update(int v, int s, int e, int l, int r, long long delta) {
  push(v, s, e);
  if (l > r) return;
  if (s == l && e == r) {
    d[v] += delta;
    push(v, s, e);
    return;
  }
  int m = (s + e) / 2;
  update(2 * v, s, m, l, min(r, m), delta);
  update(2 * v + 1, m + 1, e, max(m + 1, l), r, delta);
  t[v] = min(t[2 * v], t[2 * v + 1]);
}
void upd(int i, int l, int r, long long delta) {
  if (l > r) return;
  int L = n + l - i + 1;
  if (L > n) L -= n;
  int R = n + r - i + 1;
  if (R > n) R -= n;
  if (L <= R)
    update(1, 1, n, L, R, delta);
  else {
    update(1, 1, n, L, n, delta);
    update(1, 1, n, 1, R, delta);
  }
}
void update(int i, int l, int r, long long delta) {
  if (l > r) return;
  int R = n + i - l + 1;
  if (R > n) R -= n;
  int L = n + i - r + 1;
  if (L > n) L -= n;
  if (L <= R)
    update(1, 1, n, L, R, delta);
  else {
    update(1, 1, n, L, n, delta);
    update(1, 1, n, 1, R, delta);
  }
}
int main() {
  mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
  cin >> m >> n;
  vector<int> mas;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i].first);
    b[i].second = i;
  }
  build(1, 1, n);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    int st = 1;
    int id = lower_bound(b + st, b + n + 1, make_pair(a[i].first - m / 2, 0)) -
             b - 1;
    upd(i, st, id, m - a[i].first);
    st = id + 1;
    id = upper_bound(b + st, b + n + 1, make_pair(a[i].first, inf)) - b - 1;
    upd(i, st, id, a[i].first);
    st = id + 1;
    id = upper_bound(b + st, b + n + 1, make_pair(a[i].first + m / 2, inf)) -
         b - 1;
    upd(i, st, id, -a[i].first);
    st = id + 1;
    id = n;
    upd(i, st, id, a[i].first);
  }
  swap(a, b);
  for (int i = 1; i <= n; i++) {
    int st = 1;
    int id = lower_bound(b + st, b + n + 1, make_pair(a[i].first - m / 2, 0)) -
             b - 1;
    update(i, st, id, m - a[i].first);
    st = id + 1;
    id = lower_bound(b + st, b + n + 1, make_pair(a[i].first, 0)) - b - 1;
    update(i, st, id, a[i].first);
    st = id + 1;
    id = upper_bound(b + st, b + n + 1, make_pair(a[i].first + m / 2, inf)) -
         b - 1;
    update(i, st, id, -a[i].first);
    st = id + 1;
    id = n;
    update(i, st, id, a[i].first);
  }
  swap(a, b);
  pair<long long, int> pat = t[1];
  cout << pat.first << endl;
  int st = pat.second;
  for (int i = 1; i <= n; i++) {
    int id = a[i].second;
    answ[id] = b[st].second;
    st++;
    if (st > n) st -= n;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", answ[i]);
  }
  cout << endl;
  return 0;
}
