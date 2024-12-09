#include <bits/stdc++.h>
using namespace std;
long long a[1009], b, c, d, n, j, i, k, l, m, x;
int main() {
  cin >> n >> x;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    if (a[i] == x) l++;
    if (a[i] < x) k++;
  }
  l += x - k;
  cout << l;
}
