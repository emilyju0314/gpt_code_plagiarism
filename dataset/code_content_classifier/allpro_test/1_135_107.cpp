#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, k;
int A[maxn];
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> A[i];
  sort(A + 1, A + 1 + n);
  int ans = 0;
  n -= 2 * k;
  for (int i = 1; i <= n; i++) ans += A[i];
  for (int i = n + 1; i <= n + k; i++) {
    ans += A[i] / A[i + k];
  }
  cout << ans << "\n";
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
