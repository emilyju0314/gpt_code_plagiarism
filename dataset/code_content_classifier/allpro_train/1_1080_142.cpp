#include <bits/stdc++.h>
using namespace std;
int n;
double x, y, ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    ans = ans * (i - 1) + y;
    ans /= i;
  }
  printf("%.5lf\n", ans + 5);
  return 0;
}
