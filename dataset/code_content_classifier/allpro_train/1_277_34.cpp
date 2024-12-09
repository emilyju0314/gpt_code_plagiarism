#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
void swap(long long *xp, long long *yp) {
  long long temp = *xp;
  *xp = *yp;
  *yp = temp;
}
const long long maxn = 1e5 + 1;
void print(vector<long long> v) {
  long long i, j, n = v.size();
  for (i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long power(long long x, long long y) {
  long long res = 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y / 2;
    x = (x * x);
  }
  return res;
}
int main() {
  long long int i, j, inc, dec, t, r;
  long long int c, d, e, temp, m, p, w, k, x, y, sum, pre, temp2, mid, n, low,
      high;
  t = 1;
  n = 1;
  while (t--) {
    cin >> n >> k;
    vector<pair<long long, long long>> stool, pencil;
    vector<long long> an[k], a;
    vector<bool> v(k, false);
    double ans = 0;
    for (i = 0; i < n; i++) {
      cin >> x >> y;
      a.push_back(x);
      if (y == 1) {
        stool.push_back(make_pair(x, i));
      } else {
        pencil.push_back(make_pair(x, i));
      }
    }
    sort((stool).begin(), (stool).end());
    reverse((stool).begin(), (stool).end());
    for (i = 0; i < stool.size() && i < k; i++) {
      an[i].push_back(stool[i].second);
      v[i] = true;
    }
    if (stool.size() >= k) {
      for (; i < stool.size(); i++) {
        an[k - 1].push_back(stool[i].second);
      }
      for (i = 0; i < pencil.size(); i++) {
        an[k - 1].push_back(pencil[i].second);
      }
    } else {
      for (j = 0; i < k; i++, j++) {
        an[i].push_back(pencil[j].second);
      }
      for (; j < pencil.size(); j++) {
        an[k - 1].push_back(pencil[j].second);
      }
    }
    for (i = 0; i < k; i++) {
      m = INT_MAX;
      for (j = 0; j < an[i].size(); j++) {
        m = min(m, a[an[i][j]]);
        ans += a[an[i][j]];
      }
      if (v[i]) {
        ans -= m;
        ans += (m / (double)2);
      }
    }
    cout << setprecision(1) << fixed;
    cout << ans << "\n";
    ;
    for (i = 0; i < k; i++) {
      cout << an[i].size() << " ";
      for (j = 0; j < an[i].size(); j++) {
        cout << an[i][j] + 1 << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
