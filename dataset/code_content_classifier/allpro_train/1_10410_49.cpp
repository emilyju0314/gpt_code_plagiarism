#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long int mod = 1e9 + 7;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x % mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long int inv(long long int a) { return power(a, mod - 2); }
long long int add(long long int a, long long int b) { return (a + b) % mod; }
long long int sub(long long int a, long long int b) {
  return (a - b + mod) % mod;
}
long long int mul(long long int a, long long int b) { return (a * b) % mod; }
long long int divi(long long int a, long long int b) {
  return (a * inv(b)) % mod;
}
void pre() {}
void solve() {
  long long n, p, d;
  cin >> n >> p;
  map<long long, long long> m;
  for (int i = 0; i < n; i++) {
    cin >> d;
    m[d]++;
  }
  if (p == 1) {
    if (n % 2 == 0) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
    }
    return;
  }
  long long mo = n, val = 0;
  while (mo > 0) {
    mo /= p;
    val++;
  }
  val++;
  long long req = 0;
  long long ref = -1;
  long long lst;
  bool flag = 0;
  for (auto i = m.rbegin(); i != m.rend(); i++) {
    auto o = *i;
    if (!flag && o.second % 2 == 0) {
      continue;
    }
    if (!flag && o.second % 2 == 1) {
      ref = o.first;
      req = 1;
      flag = 1;
      lst = o.first;
      continue;
    }
    bool oo = false;
    if (lst - o.first > val) {
      break;
    }
    while (lst > o.first) {
      lst--;
      req *= p;
      if (req > n) {
        oo = true;
        break;
      }
    }
    if (oo) {
      break;
    }
    if (o.second == req) {
      flag = false;
      continue;
    }
    if (o.second < req) {
      req -= o.second;
      continue;
    }
    if ((o.second - req) % 2 == 0) {
      flag = false;
    } else {
      flag = true;
      req = 1;
      ref = o.first;
      lst = o.first;
    }
  }
  if (!flag) {
    cout << 0 << "\n";
    return;
  }
  long long ans = power(p, ref);
  for (auto i : m) {
    if (i.first >= ref) {
      break;
    }
    ans = sub(ans, mul(i.second, power(p, i.first)));
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  long long int num = 1;
  cin >> num;
  for (long long int i = 0; i < num; i++) {
    solve();
  }
}
