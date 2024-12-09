#include <bits/stdc++.h>
using namespace std;
int arr[100005], w[100005], h[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> w[i] >> h[i];
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = max((1LL * ans + h[i - 1]), arr[w[i]] * 1LL);
    cout << ans << endl;
  }
  return 0;
}
