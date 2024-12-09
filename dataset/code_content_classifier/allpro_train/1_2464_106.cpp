#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int Min = INT_MAX, Max = INT_MIN;
  while (n--) {
    int x;
    scanf("%d", &x);
    Min = min(Min, x);
    Max = max(Max, x);
  }
  int tl = max(2 * Min, Max);
  bool has = true;
  while (m--) {
    int x;
    scanf("%d", &x);
    if (x <= tl) has = false;
  }
  if (has)
    printf("%d\n", tl);
  else
    printf("-1\n");
  return 0;
}
