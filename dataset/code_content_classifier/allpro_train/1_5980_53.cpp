#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, a[200010], b[200010];
bool flag[200010];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0; i < n; i++)
    if (b[i] == 1) break;
  m = -1;
  if (i != n) {
    for (i++; i < n; i++)
      if (b[i] != b[i - 1] + 1) break;
    if (i == n) m = b[n - 1];
  }
  if (m != -1) {
    for (i = 0; i < n; i++) flag[a[i]] = true;
    for (i = 0; i < n && b[i] != 1; i++)
      if (flag[m + i + 1] == false)
        break;
      else
        flag[b[i]] = true;
    if (b[i] == 1) {
      cout << n - m << endl;
      return 0;
    }
  }
  j = 0;
  for (i = 0; i < n; i++)
    if (b[i] != 0) j = max(j, i + 1 - (b[i] - 1));
  cout << n + j << endl;
  return 0;
}
