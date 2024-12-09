#include <bits/stdc++.h>
const int INF_INT = 0x3f3f3f3f;
const long long INF_LL = 0x7f7f7f7f;
const int MOD = 1e9 + 7;
const double eps = 1e-10;
const double pi = acos(-1);
using namespace std;
int n;
int a[1000010];
int b[1000010];
int c[1000010];
int search(int l, int r, int x) {
  int ret = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (c[mid] >= x)
      ret = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return ret;
}
int main(int argc, char const *argv[]) {
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      a[x] = i;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      b[i] = a[x];
    }
    reverse(b + 1, b + 1 + n);
    c[1] = b[1];
    int len = 1;
    for (int i = 2; i <= n; i++) {
      if (b[i] > c[len]) {
        c[++len] = b[i];
      } else {
        int pos = lower_bound(c + 1, c + 1 + len, b[i]) - c;
        c[pos] = b[i];
      }
    }
    printf("%d\n", len);
  }
  return 0;
}
