#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j;
  char map[9][9];
  bool ok = false, ok1 = false;
  for (i = 0; i < 8; ++i) {
    scanf("%s", map[i]);
    for (j = 1; j < 8; ++j) {
      if (i == 0 && map[i][j] == 'W') ok1 = true;
      if (map[i][j] == map[i][j - 1]) ok = true;
    }
    if (i == 0 && map[i][0] == 'W') ok1 = true;
    if (map[i][0] == map[i][7]) ok = true;
  }
  if (!ok1 || ok)
    puts("NO");
  else
    puts("YES");
  return 0;
}
