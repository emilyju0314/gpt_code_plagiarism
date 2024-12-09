#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:600000000")
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)4e18;
const string name = "f";
struct TEvent {
  int x, v, k, l, r, up;
  TEvent() {}
  TEvent(int x, int v, int k, int l, int r, int up)
      : x(x), v(v), k(k), l(l), r(r), up(up) {}
};
bool operator<(const TEvent& a, const TEvent& b) {
  if (a.x != b.x) return a.x < b.x;
  if (a.up != b.up) return a.up < b.up;
  if (make_pair(a.l, a.r) != make_pair(b.l, b.r))
    return make_pair(a.l, a.r) < make_pair(b.l, b.r);
  return a.v < b.v;
}
const int NMAX = 200010;
const int MAGIC = 0;
int n, a[NMAX], ans[NMAX];
int t[4 * NMAX];
vector<TEvent> ev;
void solve_simple(int k) {
  int res = 0;
  for (int i = 0; i < (int)n; i++) {
    if (i > 0 && a[i] < a[(i + k - 1) / k - 1]) res++;
  }
  ans[k - 1] = res;
}
void presolve(int k) {
  int v = 0, res = 0;
  while (1) {
    int l = k * v + 1, r = k * (v + 1);
    if (l >= n) break;
    ev.push_back(TEvent(a[v], v, k, l, r, -1));
    v++;
  }
}
void update(int v, int l, int r, int p, int zn) {
  if (l > p || r < p) return;
  if (l == r) {
    t[v] += zn;
    return;
  }
  update(2 * v, l, (l + r) >> 1, p, zn);
  update(2 * v + 1, (l + r + 2) >> 1, r, p, zn);
  t[v] = t[2 * v] + t[2 * v + 1];
}
int get(int v, int l, int r, int ll, int rr) {
  if (l > rr || ll > r) return 0;
  if (ll <= l && r <= rr) return t[v];
  return get(2 * v, l, (l + r) >> 1, ll, rr) +
         get(2 * v + 1, (l + r + 2) >> 1, r, ll, rr);
  t[v] = t[2 * v] + t[2 * v + 1];
}
int main() {
  cin >> n;
  for (int i = 0; i < (int)n; i++) {
    scanf("%d", &a[i]);
  }
  memset(t, 0, sizeof(t));
  for (int i = 0; i < (int)n; i++)
    if (i) {
      if (i <= MAGIC)
        solve_simple(i);
      else
        presolve(i);
    }
  for (int i = 0; i < (int)n; i++) ev.push_back(TEvent(a[i], i, -1, -1, -1, 1));
  sort((ev).begin(), (ev).end());
  for (int i = 0; i < (int)ev.size(); i++) {
    if (ev[i].up == 1)
      update(1, 0, n - 1, ev[i].v, 1);
    else {
      ans[ev[i].k - 1] += get(1, 0, n - 1, ev[i].l, ev[i].r);
    }
  }
  for (int i = 0; i < (int)n - 1; i++) printf("%d ", ans[i]);
  return 0;
}
