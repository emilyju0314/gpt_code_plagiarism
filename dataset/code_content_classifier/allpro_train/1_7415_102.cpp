#include <bits/stdc++.h>
using namespace std;
int n, x, num1, num2, ans;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (x == 1)
      num1++;
    else if (x == 2)
      num2++;
  }
  int tmp = min(num1, num2);
  ans += tmp;
  num1 -= tmp;
  num2 -= tmp;
  if (num2 == 0) {
    ans += num1 / 3;
  }
  cout << ans << endl;
  return 0;
}
