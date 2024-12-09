#include <bits/stdc++.h>
int main() {
  int T, S, Q;
  scanf("%d %d %d", &T, &S, &Q);
  int ans = 1, down = S;
  while (down < T) {
    down += (Q - 1) * down;
    if (down < T) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
