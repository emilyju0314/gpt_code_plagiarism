#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define mod 1000000007

int32_t main() {

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), pre(n), suf(n);
    int all = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      all ^= a[i];
    }
    pre[0] = a[0];
    suf[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++) {
      pre[i] = a[i] ^ pre[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = a[i] ^ suf[i + 1];
    }
    if (all == 0) {
      cout << "YES" << endl;
      continue;
    }
    bool ok = false;
    for (int i = 0; i < n - 2; i++) {
      int x = pre[i];
      for (int j = n - 1; j >= i + 2; j--) {
        int y = suf[j];
        if (x == y && x == (all ^ x ^ y)) {
          ok = true;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }

  return 0;
}