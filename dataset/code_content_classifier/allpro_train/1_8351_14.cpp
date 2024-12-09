#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int i = 0, j = 0;
  while (1) {
    if (b[j] >= a[i]) {
      i++;
      j++;
    } else
      j++;
    if (j == m || i == n) {
      cout << n - i << endl;
      return (0);
    }
  }
  return (0);
}
