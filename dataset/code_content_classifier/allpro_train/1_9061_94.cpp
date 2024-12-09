#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * flag;
}
int n, num, l, r, x;
int Abs(int x) { return x > 0 ? x : -x; }
int main() {
  cin >> n;
  printf("? ");
  for (int i = 1; i <= n; i++) printf("0");
  puts("");
  cin >> num;
  l = 1;
  r = n;
  while (r - l >= 2) {
    int mid = (l + r) >> 1;
    printf("? ");
    for (int i = 1; i <= n; i++) {
      if (i >= l && i <= mid)
        printf("1");
      else
        printf("0");
    }
    puts("");
    cin >> x;
    if (Abs(x - num) == mid - l + 1)
      l = mid;
    else
      r = mid;
  }
  printf("? ");
  for (int i = 1; i <= n; i++) {
    if (i == l)
      printf("1");
    else
      printf("0");
  }
  puts("");
  ;
  cin >> x;
  if (x < num)
    printf("! %d %d\n", r, l);
  else
    printf("! %d %d\n", l, r);
}
