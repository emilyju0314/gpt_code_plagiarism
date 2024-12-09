#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  cin >> n >> m;
  int l[m + 5], a[n + 5], b[n + 5], c;
  c = 0;
  for (i = 0; i < n; i++) cin >> a[i] >> b[i];
  for (i = 0; i < n; i++)
    if (a[i] <= c) {
      if (b[i] >= c) c = b[i];
    } else
      break;
  if (c >= m)
    cout << "YES\n";
  else
    cout << "NO\n";
}
