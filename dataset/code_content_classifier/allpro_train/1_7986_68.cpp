#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, unsigned long long int y,
                    long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int k_ = 0; k_ < n; k_++) {
      cin >> a[k_];
    };
    vector<long long int> b(n);
    for (long long int k_ = 0; k_ < n; k_++) {
      cin >> b[k_];
    };
    long long int i = 0, empty_i = 0;
    vector<pair<long long int, long long int> > bridge(n);
    long long int prevb = 0;
    long long int flag = 0;
    while (1) {
      i++;
      i %= n;
      if (prevb >= a[i])
        prevb = b[i];
      else if (prevb + b[i] >= a[i]) {
        prevb = prevb + b[i] - a[i];
      } else {
        empty_i = i;
        prevb = 0;
        flag = 1;
      }
      if (i == 0) break;
    }
    if (empty_i == 0 and flag == 1) {
      cout << "No\n";
      continue;
    }
    i = empty_i;
    long long int flag2 = 0;
    prevb = 0;
    while (1) {
      i++;
      i %= n;
      if (prevb >= a[i])
        prevb = b[i];
      else if (prevb + b[i] >= a[i]) {
        prevb = prevb + b[i] - a[i];
      } else {
        flag2 = 1;
        break;
      }
      if (i == empty_i) break;
    }
    if (flag2)
      cout << "No\n";
    else
      cout << "Yes\n";
  }
  return 0;
}
