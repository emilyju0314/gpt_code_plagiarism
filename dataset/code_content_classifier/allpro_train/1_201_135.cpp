#include <bits/stdc++.h>
using namespace std;
int n;
long long quick(long long x, int y) {
  long long e = 1;
  while (y > 0) {
    if (x >= n || e >= n || e * x >= n) return n + 1;
    if (y % 2 == 1) {
      e = e * x;
    }
    x = x * x;
    y /= 2;
  }
  return e;
}
int judge(int x, int y) {
  int L = x, R = n, ret = n;
  while (L <= R) {
    int mid = (L + R) / 2;
    if (quick(mid, y) >= n) {
      R = mid - 1;
      ret = mid;
    } else
      L = mid + 1;
  }
  return (ret - x) % 2;
}
int dfs(int x, int y) {
  if (quick(x, y) >= n) return 1;
  if (x == 1 && quick(2, y) >= n) return 1;
  if (quick(x, y + 1) >= n) return !judge(x, y);
  return !dfs(x + 1, y) | !dfs(x, y + 1);
}
int main() {
  int a, b;
  scanf("%d%d%d", &a, &b, &n);
  if (a == 1 && quick(2, b) >= n) {
    printf("Missing");
  } else if (dfs(a, b)) {
    printf("Masha");
  } else {
    printf("Stas\n");
  }
  return 0;
}
