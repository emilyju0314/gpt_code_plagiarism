#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, i, j, a, b;
  char c;
  int m[367];
  int f[367];
  for (i = 0; i < 367; i++) f[i] = m[i] = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> c >> a >> b;
    if (c == 'M') {
      for (j = a; j <= b; j++) m[j]++;
    } else {
      for (j = a; j <= b; j++) f[j]++;
    }
  }
  int maxx = 0, p = 0;
  for (i = 1; i <= 366; i++) {
    m[i] = min(m[i], f[i]);
    maxx = max(maxx, m[i]);
  }
  cout << maxx * 2;
  return 0;
}
