#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, a;
  scanf("%d%d%d", &l, &r, &a);
  if (l > r) {
    int tmp = l;
    l = r;
    r = tmp;
  }
  if (l + a > r)
    printf("%d", (l + a + r) / 2 * 2);
  else
    printf("%d", (l + a) * 2);
  return 0;
}
