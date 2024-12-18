#include <bits/stdc++.h>
using namespace std;
int D, M, Y, d, m, y, f[3];
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check() {
  if (m < M)
    return true;
  else if (m == M)
    return d <= D;
  return false;
}
int main() {
  scanf("%d.%d.%d", &D, &M, &Y);
  scanf("%d.%d.%d", &f[0], &f[1], &f[2]);
  sort(f, f + 3);
  do {
    d = f[0], m = f[1], y = f[2];
    if (m > 12) continue;
    if (d > day[m] + (y % 4 == 0 and m == 2)) continue;
    if (Y - y > 18 or (Y - y == 18 and check())) {
      printf("YES\n");
      return 0;
    }
  } while (next_permutation(f, f + 3));
  printf("NO\n");
  return 0;
}
