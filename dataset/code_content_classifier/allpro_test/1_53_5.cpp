#include <bits/stdc++.h>
using namespace std;
char v[300005];
bool check(int a, int n, char c) {
  for (int i = a; i <= n; i += a) {
    if (v[i] != c) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int m, t, i, j, k;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n;
    char c;
    cin >> c;
    int ok = 0;
    for (i = 1; i <= n; ++i) cin >> v[i];
    for (i = 1; i <= n; ++i)
      if (v[i] != c) ok = 1;
    if (ok == 0) {
      cout << "0\n";
      continue;
    }
    for (i = 2; i <= n; ++i) {
      if (check(i, n, c)) break;
    }
    if (i <= n) {
      cout << "1\n";
      cout << i << '\n';
      continue;
    }
    cout << "2\n";
    cout << n << ' ' << n - 1 << '\n';
  }
  return 0;
}
