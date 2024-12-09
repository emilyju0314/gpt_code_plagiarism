#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long bb[N];
long long a[N];
long long st[N];
long long cnt;
long long dfs(long long u) {
  if (u > 10) return 0;
  long long t = 0;
  for (long long i = u - 1; i >= 0; i--) {
    if (a[i] == 1) a[i] = 4;
    if (a[i] == 2) a[i] = 7;
    t = t * 10 + a[i];
  }
  bb[cnt++] = t;
  for (long long i = 1; i <= 2; i++) {
    a[u] = i;
    dfs(u + 1);
  }
  return 0;
}
int main(void) {
  dfs(0);
  sort(bb, bb + cnt);
  long long n, m;
  cin >> n >> m;
  long long x = lower_bound(bb + 1, bb + cnt, n) - bb;
  long long y = lower_bound(bb + 1, bb + cnt, m) - bb;
  if (y - x == 0) {
    long long t = m - n;
    cout << bb[y] * (t + 1) << endl;
  } else {
    long long sum = 0;
    sum = (bb[x] - n + 1) * bb[x];
    sum += (m - bb[y - 1]) * bb[y];
    for (long long i = x + 1; i < y; i++) {
      long long t = bb[i] - bb[i - 1];
      sum += t * bb[i];
    }
    cout << sum << endl;
  }
  return 0;
}
