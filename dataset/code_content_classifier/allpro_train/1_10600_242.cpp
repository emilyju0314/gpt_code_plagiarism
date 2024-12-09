#include <bits/stdc++.h>
using namespace std;
int n, sum, a, b;
int num0, ans;
int main() {
  scanf("%d", &n);
  num0 = sum = 0;
  for (int i = 0; i < 2 * n; i++) {
    scanf("%d.%d", &a, &b);
    if (b == 0) num0++;
    sum += b;
  }
  ans = n * 1000;
  for (int i = 0; i <= min(n, num0); i++)
    ans = min(ans, abs(sum - (n - i) * 1000));
  printf("%.3lf\n", ans / 1000.0);
}
