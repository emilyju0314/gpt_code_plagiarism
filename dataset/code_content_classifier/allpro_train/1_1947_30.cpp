#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 50;
const int M = 1e6 + 50;
const long long INF = 2e18 + 5;
double eps = 1e-6;
int n, l;
long long t[N];
char str[6] = {"LDUR"};
void godie() {
  puts("NO");
  exit(0);
}
struct node {
  long long k, b, id;
  bool operator<(const node &rhs) const { return id < rhs.id; }
} p[N];
void Merge(pair<int, int> &x, pair<int, int> y) {
  if (y.first > y.second) godie();
  x.first = max(x.first, y.first);
  x.second = min(x.second, y.second);
  if (x.first > x.second) godie();
}
long long fl(long long &x, long long y) {
  if (x >= 0) return x / y;
  return x / y - (x % y ? 1 : 0);
}
long long cl(long long x, long long y) {
  if (x >= 0) return (x + y - 1) / y;
  return x / y;
}
int ans[2][N];
void solve(long long *x, int n, int *ans) {
  for (int i = 1; i <= n; i++) {
    if ((x[i] + t[i]) & 1) godie();
    x[i] = (x[i] + t[i]) / 2;
  }
  int cnt = 0;
  p[cnt++] = (node){0, 0, 0};
  p[cnt++] = (node){1, 0, l};
  for (int i = 1; i <= n; i++) p[cnt++] = (node){-(t[i] / l), x[i], t[i] % l};
  sort(p, p + cnt);
  pair<int, int> best = pair<int, int>(0, l);
  for (int i = 1; i < cnt; i++) {
    long long k = p[i].k - p[i - 1].k;
    long long b = p[i].b - p[i - 1].b;
    long long c = p[i].id - p[i - 1].id;
    if (!k) {
      if (c < b) godie();
    } else {
      long long L = -b, R = c - b;
      if (k < 0) L *= -1, R *= -1, swap(L, R), k *= -1;
      Merge(best, pair<int, int>(cl(L, k), fl(R, k)));
    }
  }
  long long sl = best.first;
  long long s = 0;
  int pos = 0;
  for (int i = 0; i < cnt; i++) {
    long long val = p[i].b + sl * p[i].k;
    while (s < val) {
      s++;
      ans[++pos] = 1;
    }
    while (pos < p[i].id) ans[++pos] = 0;
  }
}
long long x[N], y[N], x1[N], x2[N];
int main() {
  scanf("%d%d", &n, &l);
  for (int i = 1; i <= n; i++) scanf("%I64d%I64d%I64d", &t[i], &x[i], &y[i]);
  for (int i = 1; i <= n; i++) x1[i] = x[i] + y[i], x2[i] = x[i] - y[i];
  solve(x1, n, ans[0]);
  solve(x2, n, ans[1]);
  for (int i = 1; i <= l; i++) printf("%c", str[ans[0][i] * 2 + ans[1][i]]);
  return 0;
}
