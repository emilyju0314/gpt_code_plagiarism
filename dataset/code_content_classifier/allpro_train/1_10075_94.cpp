#include <bits/stdc++.h>
int main() {
  int x, t, a, b, da, db;
  while (scanf("%d%d%d%d%d%d", &x, &t, &a, &b, &da, &db) == 6) {
    bool suc = false;
    for (int i = 0; i < t; ++i)
      for (int j = 0; j < t; ++j) {
        if (x == 0 || (x == (a - i * da + b - j * db)) || x == a - i * da ||
            x == b - j * db) {
          suc = true;
          break;
        }
      }
    puts(suc ? "YES" : "NO");
  }
  return 0;
}
