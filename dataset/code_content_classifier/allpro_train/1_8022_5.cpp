#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int p[2006];
int g;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    if (!i)
      g = p[i];
    else
      g = gcd(g, p[i]);
    if (p[i] == 1) cnt++;
  }
  int len = 0x3f3f3f3f;
  if (g > 1)
    printf("-1");
  else {
    if (cnt) {
      printf("%d\n", n - cnt);
    } else {
      for (int i = 0; i < n; i++) {
        int tg = p[i];
        for (int j = i + 1; j < n; j++) {
          tg = gcd(tg, p[j]);
          if (tg == 1) {
            len = min(len, j - i);
            break;
          }
        }
      }
      printf("%d\n", len + n - 1);
    }
  }
}
