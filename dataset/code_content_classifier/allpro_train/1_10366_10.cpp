#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int i, j, k, a, b, c, temp, n;
  cin >> n;
  int ara[2 * n];
  for (i = 1; i <= n; i++) cin >> ara[i];
  for (i = 1; i <= n; i++) {
    b = ara[i];
    if (ara[b] == i) continue;
    c = ara[b];
    if (ara[c] == i) {
      cout << "YES";
      exit(0);
    }
  }
  cout << "NO";
}
