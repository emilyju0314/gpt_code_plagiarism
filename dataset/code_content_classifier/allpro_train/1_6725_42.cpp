#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int nec = 0, cet = 0, x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x % 2 != 0)
      nec = nec + 1;
    else
      cet = cet + 1;
  }
  int ans;
  if (nec < cet)
    ans = nec;
  else {
    ans = cet;
    nec = nec - cet;
    ans = ans + nec / 3;
  }
  printf("%d\n", ans);
  return 0;
}
