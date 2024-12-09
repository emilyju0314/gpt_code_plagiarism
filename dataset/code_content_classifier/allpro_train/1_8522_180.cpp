#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, k;
long long a[500010], now, b[500010], c[500010];
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (j = 1; j <= m; j++) cin >> k, b[k] = 1;
  k = 0;
  for (i = 1; i <= n; i++)
    if (b[i] == 0) {
      now += a[i];
    } else {
      k++;
      c[k] = a[i];
    }
  sort(c + 1, c + k + 1);
  reverse(c + 1, c + k + 1);
  for (j = 1; j <= k; j++) now += max(now, c[j]);
  cout << now << endl;
}
