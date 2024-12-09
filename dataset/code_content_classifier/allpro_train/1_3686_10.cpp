#include <bits/stdc++.h>
using namespace std;
int fx[] = {0, 0, -1, 1, -1, 1, 1, -1};
int fy[] = {1, -1, 0, 0, 1, 1, -1, -1};
int ara[10000];
int poin[10000];
int main() {
  int n, c;
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ara[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &poin[i]);
  }
  int x = 0, y, ans = 0, res = 0;
  for (int i = 0; i < n; i++) {
    x += poin[i];
    y = ara[i] - x * c;
    ans += max(0, y);
  }
  x = 0;
  for (int i = n - 1; i >= 0; i--) {
    x += poin[i];
    y = ara[i] - x * c;
    ans -= max(0, y);
  }
  if (ans > 0)
    printf("Limak\n");
  else if (ans < 0)
    printf("Radewoosh\n");
  else
    printf("Tie\n");
  return 0;
}
