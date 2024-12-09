#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100], j[100], n, i = 0, h[100], l = 1, m = 0;
  cin >> n;
  for (; i < n; i++) {
    cin >> a[i];
    j[i] = 2001 + i;
  }
  for (i = 0; i < n; i++)
    if (a[i] == l) {
      h[m] = j[i];
      m++;
      l++;
    }
  if (m == 0) {
    cout << 0;
    return (0);
  }
  cout << m << endl;
  for (i = 0; i < m; i++) cout << h[i] << " ";
}
