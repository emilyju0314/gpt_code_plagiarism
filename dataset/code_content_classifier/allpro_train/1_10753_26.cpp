#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;
signed main() {
  ios_base::sync_with_stdio(false);
  long long n, m;
  string s;
  cin >> n >> m;
  vector<string> a, b;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    a.push_back(s);
  }
  for (long long i = 0; i < m; i++) {
    cin >> s;
    b.push_back(s);
  }
  long long q;
  cin >> q;
  while (q--) {
    long long x;
    cin >> x;
    if (x % n == 0)
      cout << a[n - 1];
    else
      cout << a[x % n - 1];
    if (x % m == 0)
      cout << b[m - 1];
    else
      cout << b[x % m - 1];
    cout << endl;
  }
}
