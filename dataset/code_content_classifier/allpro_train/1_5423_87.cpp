#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct vec {
  int x[6];
  int operator*(vec obj) {
    int ans = 0;
    for (int i = 1; i <= 5; i++) ans += x[i] * obj.x[i];
    return ans;
  }
  vec operator-(vec obj) {
    vec ans;
    for (int i = 1; i <= 5; i++) ans.x[i] = x[i] - obj.x[i];
    return ans;
  }
  void vread() {
    for (int i = 1; i <= 5; i++) x[i] = read();
  }
} p[1100];
int n;
int bad[1100];
int main() {
  n = read();
  if (n >= 12) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) p[i].vread();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == i) continue;
      for (int k = 1; k <= n; k++) {
        if (k == j || k == i) continue;
        vec tmp1 = p[i] - p[j], tmp2 = p[i] - p[k];
        if (tmp1 * tmp2 > 0) {
          bad[i] = 1;
          goto nextstep;
        }
      }
    }
  nextstep:;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += bad[i];
  }
  printf("%d\n", n - ans);
  for (int i = 1; i <= n; i++) {
    if (bad[i] == 0) {
      printf("%d\n", i);
    }
  }
  return 0;
}
