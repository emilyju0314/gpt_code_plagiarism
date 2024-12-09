#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    long long int ans = 0;
    if (b % a != 0)
      ans = -1;
    else {
      long long int count = 0, cnt = 0;
      b /= a;
      while (b > 1) {
        if (b % 2 != 0) cnt++;
        count++;
        b /= 2;
      }
      ans += count / 3;
      count %= 3;
      ans += count / 2;
      count %= 2;
      ans += count;
      if (cnt != 0) ans = -1;
    }
    cout << ans << endl;
  }
  return 0;
}
