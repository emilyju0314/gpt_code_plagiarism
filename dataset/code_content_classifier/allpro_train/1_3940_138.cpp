#include <bits/stdc++.h>
using namespace std;
void work() {
  int n, k, c, t, s = 0, last = 0;
  scanf("%d%d%d", &n, &k, &c);
  for (int i = 0; i < c; ++i) {
    scanf("%d", &t);
    s += (t - last - 1) / k + 1;
    last = t;
  }
  s += (n - last) / k;
  printf("%d\n", s);
}
int main() {
  work();
  return 0;
}
