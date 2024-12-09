#include <bits/stdc++.h>
using namespace std;
long long n, m, k, a[100010];
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) scanf("%I64d", &a[i]);
  long long j = 1, s = 0, ans = 0;
  for (int i = 1; i <= m; i = j) {
    int t = 0;
    for (; (a[j] - s - 1) / k == (a[i] - s - 1) / k && j <= m; j++) t++;
    s += t;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
