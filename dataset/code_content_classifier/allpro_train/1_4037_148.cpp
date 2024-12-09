#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  double angle = 180 - 360.0 / n, ans = 1e6;
  angle /= n - 2;
  printf("2 1 ");
  int tag;
  for (int i = 1; i <= n - 2; i++) {
    if (fabs(i * angle - a) < fabs(ans - a)) {
      ans = i * angle;
      tag = i;
    }
  }
  printf("%d", 2 + tag);
  return 0;
}
