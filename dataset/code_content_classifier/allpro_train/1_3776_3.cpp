#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
const int MAXN = 1000001;
int n;
long long t[4 * MAXN];
long long sum(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return sum(v * 2, tl, tm, l, min(r, tm)) +
         sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
long long sum(int l, int r) {
  if (l > r) return sum(1, 0, n - 1, l, n - 1) + sum(1, 0, n - 1, 0, r);
  return sum(1, 0, n - 1, l, r);
}
void inc(int v, int tl, int tr, int pos) {
  if (tl == tr)
    t[v]++;
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      inc(v * 2, tl, tm, pos);
    else
      inc(v * 2 + 1, tm + 1, tr, pos);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}
int main() {
  int k;
  cin >> n >> k;
  int x = 0;
  long long s = 1;
  for (int i = 0; i < n; i++) {
    int y;
    long long p;
    y = (x + k) % n;
    if (2 * k >= n)
      p = sum(y + 1, x - 1);
    else
      p = sum(x + 1, y - 1);
    s += p + 1;
    printf("%I64d ", s);
    inc(1, 0, n - 1, x);
    inc(1, 0, n - 1, y);
    x = y;
  }
  return 0;
}
