#include <bits/stdc++.h>
using namespace std;
int dp[16];
int a[100001];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int t;
      cin >> t;
      a[i] |= (t << j);
    }
    dp[a[i]] = i + 1;
  }
  if (dp[0]) {
    cout << "YES\n";
  } else {
    bool ok = 0;
    int u = (1 << k);
    for (int i = 1; i < u; i++) {
      for (int j = i + 1; j < u; j++) {
        if ((i & j) == 0 && dp[i] && dp[j]) {
          ok = 1;
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
