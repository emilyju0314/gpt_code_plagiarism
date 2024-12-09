#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int num[maxn];
int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> num[i];
    }
    sort(num + 1, num + n + 1);
    long long ans = 0;
    for (int i = n; i > 1; i--) {
      while (1) {
        num[i] += num[1];
        if (num[i] <= k)
          ans++;
        else
          break;
      }
    }
    cout << ans << '\n';
  }
}
