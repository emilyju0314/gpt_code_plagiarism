#include <bits/stdc++.h>
using namespace std;
inline long long isqrt(long long k) {
  long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline long long mnz(long long& a, long long b) { return a = (a > b ? b : a); }
inline long long mxz(long long& a, long long b) { return a = (a < b ? b : a); }
inline string toString(long long n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
double const eps = 1e-6;
long long const Base = 1e9 + 7, oo = 1e17, MAXN = 1e6;
long long A[MAXN + 5];
vector<pair<long long, long long> > compress(vector<long long> vec) {
  sort((vec).begin(), (vec).end());
  vector<pair<long long, long long> > v;
  long long cnt = 1;
  for (long long i = 1; i <= (long long)vec.size(); i++) {
    if (i == (long long)vec.size() or vec[i] != vec[i - 1]) {
      v.push_back(make_pair(vec[i - 1], cnt));
      cnt = 1;
    } else
      cnt++;
  }
  return v;
}
vector<pair<long long, long long> > v2;
long long Solves() {
  long long n, m, k, cnt = 0, ans = oo, x, y, q, c, sum = 0, v, t;
  cin >> n;
  vector<long long> vec;
  for (long long i = 1; i <= n; i++) cin >> x, vec.push_back(x);
  v2.clear();
  v2 = compress(vec);
  for (long long i = 0; i < v2.size(); i++) mnz(v, v2[i].second + 1);
  for (long long i = 1; i <= n; i++) {
    if (n % i == 0 or n / i + n % i >= i - 1) {
      v = 0;
      for (long long j = (long long)v2.size() - 1; j >= 0; j--) {
        c = v2[j].second;
        if (c % i == 0)
          v += c / i;
        else {
          if (c / i + c % i >= i - 1)
            v += c / i + 1;
          else {
            v = oo;
            break;
          }
        }
      }
      mnz(ans, v);
    }
  }
  cout << ans << endl;
  return 0;
}
int main() {
  if (fopen("locin.txt", "r")) freopen("locin.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  cin >> test;
  for (long long T = 1; T <= test; T++) {
    Solves();
  }
}
