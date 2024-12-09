#include <bits/stdc++.h>
using namespace std;
int ar[202 + 2];
vector<int> v;
int main() {
  int n, i, j, k, x;
  scanf("%d", &n);
  int z = 0, h = 0, d = 0, on = 0, othr = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    ar[i] = x;
    if (x == 100)
      h = 100;
    else if (x == 0)
      z = 1;
    else if (x % 10 == 0)
      d = x;
    else if (x >= 1 && x < 10)
      on = x;
    else
      othr = x;
  }
  if (z) v.push_back(0);
  if (on) v.push_back(on);
  if (d) v.push_back(d);
  if (h) v.push_back(h);
  int sz = (int)(v.size());
  if (!sz)
    printf("1\n%d\n", ar[1]);
  else {
    if (h && (!d && !on) && othr) v.push_back(othr);
    if (z && (!d && !on && !h) && othr) v.push_back(othr);
    sz = (int)(v.size());
    printf("%d\n", sz);
    for (i = 0; i < sz; i++) {
      printf("%d ", v[i]);
    }
    printf("\n");
  }
  return 0;
}
