#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0;
  bool flg = false;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') flg = true;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return flg ? -x : x;
}
int n, m, k, p;
int h[100010], a[100010];
int gettime(long long x, int h, int a, int t) {
  if (x / a < t - 1) return t - 1 - x / a;
  if (x - 1LL * a * (t - 1) < h) return 0;
  return -1;
}
bool check(long long x) {
  static int tot[100010];
  for (int i = 1; i <= n; i++) tot[i] = 0;
  priority_queue<pair<int, int> > que;
  for (int i = 1; i <= n; i++) {
    int t = gettime(x, h[i], a[i], m + 1);
    if (~t) que.push((pair<int, int>){t, i});
  }
  for (int i = m; i; i--) {
    if (!que.empty() && que.top().first == i) return 0;
    for (int j = 1; j <= k; j++) {
      if (que.empty()) return 1;
      int e = que.top().second;
      que.pop();
      tot[e]++;
      int t = gettime(x - 1LL * (m - i + 1) * a[e] + 1LL * tot[e] * p, h[e],
                      a[e], i);
      if (~t) que.push((pair<int, int>){t, e});
    }
  }
  return que.empty();
}
int main() {
  n = read(), m = read(), k = read(), p = read();
  long long l = 0, r = 0, mid;
  for (int i = 1; i <= n; i++)
    h[i] = read(), a[i] = read(), r = max(r, h[i] + 1LL * a[i] * m);
  while (l < r) {
    mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%I64d\n", l);
  return 0;
}
