#include <bits/stdc++.h>
using namespace std;
int n, q, b, d;
int a[1000][1000];
int fc[1000];
int fr[1000];
int rr[1000];
int main() {
  ios::sync_with_stdio(false);
  scanf("%d", &n);
  memset(fc, 0, sizeof(fc));
  memset(fr, 0, sizeof(fr));
  memset(rr, 0, sizeof(rr));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  long long sol = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sol += a[i][j] * a[j][i];
    }
  }
  sol %= 2;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &b);
    if (b == 1 || b == 2) {
      scanf("%d", &d);
      d--;
      sol ^= 1;
    } else if (b == 3) {
      printf("%d", sol);
    }
  }
  return 0;
}
