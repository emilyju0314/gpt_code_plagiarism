#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
const long long int mod2 = 1e18 + 5;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long int> v;
  for (int i = 0; i < n; i++) {
    long long int a;
    cin >> a;
    v.push_back(a);
  }
  int res = n;
  for (int i = 0; i < n; i++) {
    set<int> s;
    int cnt = 0;
    for (int j = 0; j < i; j++) {
      int taille = s.size();
      s.insert(v[j]);
      if (s.size() == taille) {
        break;
      } else
        cnt++;
    }
    int cnt1 = 0;
    for (int j = n - 1; j >= cnt; j--) {
      int taille = s.size();
      s.insert(v[j]);
      if (s.size() == taille) {
        break;
      } else
        cnt1++;
    }
    res = min(res, n - cnt - cnt1);
  }
  cout << res << endl;
  return 0;
}
