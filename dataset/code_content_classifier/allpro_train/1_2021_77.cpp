#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long sum[maxn];
int v[maxn], n;
int cmp(const int &i, const int &j) { return i > j; }
long long get(int x, int y) {
  long long ret = 1;
  while (y--) ret *= x;
  return ret;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    sort(v + 1, v + n + 1, cmp);
    sum[0] = 0;
    long long ret1 = 0;
    for (int i = 1; i <= n; i++) {
      sum[i] = v[i] + sum[i - 1];
      ret1 += (long long)v[i] * (i - 1);
    }
    int m;
    scanf("%d", &m);
    while (m--) {
      int k;
      scanf("%d", &k);
      if (k == 1)
        printf("%I64d ", ret1);
      else {
        int now = 0;
        long long ret = 0;
        for (int i = 0; now < n; i++) {
          int f = (int)min((long long)n - now, get(k, i));
          ret += (long long)(sum[f + now] - sum[now]) * i;
          now += f;
        }
        printf("%I64d ", ret);
      }
    }
    puts("");
  }
  return 0;
}
