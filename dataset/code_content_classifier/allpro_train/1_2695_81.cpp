#include <bits/stdc++.h>
using namespace std;
int n, k;
int cnt[1010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> n >> k) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1, x; i <= n; ++i) {
      cin >> x;
      cnt[x]++;
    }
    int ans = 0;
    int need = n / 2 + (n & 1);
    for (int i = 1; i <= k; ++i) {
      while (cnt[i] >= 2 && need > 0) {
        --need;
        cnt[i] -= 2;
        ans += 2;
      }
    }
    cout << ans + need << endl;
  }
  return 0;
}
