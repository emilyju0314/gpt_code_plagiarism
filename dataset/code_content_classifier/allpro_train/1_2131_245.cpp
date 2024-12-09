#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
int main() {
  int(n);
  scanf("%d", &n);
  printf("YES\n");
  for (int(i) = 0; (i) < (int)(n); ++(i)) {
    int x1, y1;
    scanf("%d%d", &x1, &y1);
    int x2, y2;
    scanf("%d%d", &x2, &y2);
    int x = max(x1, x2), y = max(y1, y2);
    int ans = abs(x) % 2 + abs(y) % 2 * 2 + 1;
    printf("%d\n", ans);
  }
}
