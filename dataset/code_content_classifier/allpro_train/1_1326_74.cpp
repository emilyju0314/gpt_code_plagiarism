#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 123456789101112, a[100005];
  sort(a, a + n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 1; i <= 10000000; i++) {
    long long res = 0;
    long long cnt = 1;
    for (int j = 0; j < n; j++) {
      res += abs(cnt - a[j]);
      cnt *= i;
      if (res > ans) break;
    }
    if (res > ans) break;
    ans = min(ans, res);
  }
  cout << ans;
}
