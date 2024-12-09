#include <bits/stdc++.h>
using namespace std;
int n, b[111][111], bit[111][40], a[111];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
      if (b[i][j] < 0) continue;
      for (int k = 0; k < 31; k++)
        if (b[i][j] >> k & 1) bit[i][k] = bit[j][k] = 1;
    }
  for (int i = 0; i < n; i++)
    for (int k = 0; k < 31; k++) a[i] |= bit[i][k] << k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (b[i][j] < 0) a[i] = max(a[i], a[j]), a[j] = a[i];
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
}
