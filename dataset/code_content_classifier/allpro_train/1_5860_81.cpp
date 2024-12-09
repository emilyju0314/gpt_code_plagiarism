#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 10;
const int MAX_N = 200 * 1000 + 10;
int a[MAX_N], nex[MAX_N];
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int i = n; i; i--) nex[i - 1] = (a[i] != 1 ? i : nex[i]);
  for (int i = 0; i < n; i++) {
    int cur = i, s = 0, p = 1;
    while (cur < n && INF / a[cur] > p) {
      s += a[cur], p *= a[cur];
      int L = 0, R = nex[cur] - cur;
      while (L + 1 < R) {
        int mid = (L + R) / 2;
        p >= 1LL * k*(s + mid) ? L = mid : R = mid;
      }
      ans += (p == 1LL * k * (s + L)), s += nex[cur] - cur - 1, cur = nex[cur];
    }
  }
  cout << ans << endl;
  return 0;
}
