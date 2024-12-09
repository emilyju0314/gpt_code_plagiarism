#include <bits/stdc++.h>
using namespace std;
int n, arr[5010], cnt = 0, ans = 0, inf = 5100;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  while (1) {
    for (int i = 0; i < n; i++)
      if (arr[i] <= cnt) arr[i] = inf, cnt++;
    if (cnt == n) break;
    ans++;
    for (int i = n - 1; i >= 0; i--)
      if (arr[i] <= cnt) arr[i] = inf, cnt++;
    if (cnt == n) break;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
