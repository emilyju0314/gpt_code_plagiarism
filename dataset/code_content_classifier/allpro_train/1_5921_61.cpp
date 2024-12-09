#include <bits/stdc++.h>
using namespace std;
int v[200], n, m, a, b, c, i, d;
int main(void) {
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> a >> b >> c;
    v[a] = v[a] - c;
    v[b] = v[b] + c;
  }
  for (i = 0; i <= n; i++)
    if (v[i] < 0) d = d - v[i];
  cout << d;
  return 0;
}
