#include <bits/stdc++.h>
using namespace std;
long long x, ans, b = 1;
int sumOfDigits(long long a) {
  int ans = 0;
  while (a) {
    ans += a % 10;
    a /= 10;
  }
  return ans;
}
int main() {
  cin >> x;
  ans = x;
  while (x) {
    long long cur = (x - 1) * b + (b - 1);
    if (sumOfDigits(cur) > sumOfDigits(ans) ||
        (sumOfDigits(cur) == sumOfDigits(ans) && cur > ans)) {
      ans = cur;
    }
    x /= 10;
    b *= 10;
  }
  cout << ans << endl;
  return 0;
}
