#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t, a, b, p, n, i, j, ans;
  string s;
  vector<long long int> v;
  cin >> t;
  while (t--) {
    cin >> a >> b >> p;
    cin >> s;
    n = s.size();
    v.resize(n);
    v[0] = 0;
    if (s[0] == 'A')
      v[1] = a;
    else
      v[1] = b;
    for (i = 2; i < n; i++) {
      if (s[i - 1] != s[i - 2]) {
        if (s[i - 1] == 'A')
          v[i] = v[i - 1] + a;
        else
          v[i] = v[i - 1] + b;
      } else
        v[i] = v[i - 1];
    }
    if (p >= v[n - 1])
      ans = 1;
    else {
      ans = n;
      for (i = 1; i < n - 1; i++) {
        if (v[i] != v[i + 1]) {
          j = v[n - 1] - v[i];
          if (p >= j) {
            ans = i + 1;
            break;
          }
        }
      }
    }
    cout << ans << endl;
    ans = 1;
  }
}
