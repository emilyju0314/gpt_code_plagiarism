#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> pos(N, 0);
inline void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x] = i + 1;
  }
  if (pos[1]) {
    int i = 1, j;
    for (i = 2; pos[i] == pos[1] + i - 1; i++)
      ;
    if (pos[i - 1] == n) {
      for (j = i; j <= n && pos[j] <= j - i; j++)
        ;
      if (j > n) {
        cout << n - i + 1 << '\n';
        return;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, pos[i] - i + 1 + n);
  }
  cout << ans << '\n';
}
int32_t main() {
  clock_t startTime;
  startTime = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << setprecision(10);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
