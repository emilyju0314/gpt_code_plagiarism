#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;
const int INFINITE = 0x3FFFFFFF;
int n, r, q, step;
int x[MAXN];
inline int getAns(int n, int a, int b) {
  int res = -1;
  for (; b > 0; a %= b, swap(a, b)) {
    n -= a / b;
    res += a / b - 1;
  }
  return (a == 1 && n == 0) ? res : INFINITE;
}
inline void printAns(int a, int b) {
  int n = 1;
  for (; b > 0; a %= b, swap(a, b)) x[++n] = a / b;
  x[n]--;
  printf("T");
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= x[n + 1 - i]; ++j) printf("%c", (i & 1) ? 'B' : 'T');
  printf("\n");
}
int main() {
  scanf("%d %d\n", &n, &r);
  if (r == 1)
    printf((n == 1) ? "0\nT\n" : "IMPOSSIBLE\n");
  else {
    int res = INFINITE;
    for (int i = 1; i < r; ++i) {
      int ans = getAns(n, r, i);
      if (res > ans) res = ans, q = i;
    }
    if (res == INFINITE)
      printf("IMPOSSIBLE\n");
    else {
      printf("%d\n", res);
      printAns(r, q);
    }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
