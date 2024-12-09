#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N];
long long bal[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    int zeros = 0, ones = 0;
    for (int i = 0; i <= n; i++) {
      if (i) {
        if (a[i])
          ones++;
        else
          zeros++;
      }
      bal[i] = zeros - ones;
    }
    long long tot = bal[n];
    long long ans = 0;
    if (x == 0) ans++;
    for (int i = 1; i <= n; i++) {
      if (x == bal[i] && tot == 0) {
        ans = -1;
        break;
      }
      if (tot == 0) {
        continue;
      }
      if ((x - bal[i]) % tot == 0) {
        if ((x - bal[i]) / tot >= 0) ans++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
