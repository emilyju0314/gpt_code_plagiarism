#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, a, b;
  cin >> n >> m >> a >> b;
  if (a * m < b) {
    cout << a * n;
  } else {
    long long int ans = (n / m) * b;
    if ((n - (n / m) * m) * a > b)
      ans += b;
    else
      ans += (n - (n / m) * m) * a;
    cout << ans;
  }
  return 0;
}
