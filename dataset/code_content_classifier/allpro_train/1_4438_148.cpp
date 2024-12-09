#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, m, a[N], d[N];
int main() {
  int T;
  scanf("%d", &T);
  for (int ci = 1; ci <= T; ci++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int now = 1;
    d[now] = 0;
    for (int i = 2; i <= n; now++) {
      int r = i + 1;
      for (r = i + 1; r <= n; r++)
        if (a[r] <= a[r - 1]) break;
      for (int j = i; j < r; j++) d[j] = d[now] + 1;
      i = r;
    }
    printf("%d\n", d[n]);
  }
  return 0;
}
