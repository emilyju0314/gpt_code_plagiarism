#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:216000000")
using namespace std;
const long long MAX = 1000000LL * 1000000LL;
const long long MIN = numeric_limits<long long>::min();
const double PI = 3.14159265358979;
const long long MOD = 1000000LL;
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (int i = 0; i < v.size(); ++i) out << v[i] << " ";
  return out;
}
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (int i = 0; i < v.size(); ++i) in >> v[i];
  return in;
}
template <class T>
T lexical_cast(string& s) {
  stringstream ss(s);
  T t;
  ss >> t;
  return t;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long cdiv(long long a, long long b) {
  return (a % b) ? (a / b + 1) : (a / b);
}
long long inv(long long n, long long mod) {
  long long pow = mod - 2;
  long long ans = 1;
  long long cur = n;
  while (pow > 0) {
    if (pow & 1) {
      ans *= cur;
      ans %= mod;
    }
    pow /= 2;
    cur *= cur;
    cur %= mod;
  }
  return ans;
}
template <class Cont>
void sort(Cont& c) {
  sort(begin(c), end(c));
}
template <class Cont>
void reverse(Cont& c) {
  reverse(begin(c), end(c));
}
bool should_del(map<long long, long long>::iterator b,
                map<long long, long long>& cont) {
  if (b == cont.begin() || b == cont.end()) return false;
  auto a = prev(b);
  auto c = next(b);
  if (c == cont.end()) return false;
  return !((b->second - a->second) * (c->first - a->first) <
           (c->second - a->second) * (b->first - a->first));
}
int main() {
  ios_base::sync_with_stdio(false);
  int q;
  long long m;
  cin >> q >> m;
  map<long long, long long> hull;
  hull[0] = 0;
  hull[-1] = 0;
  long long succ = 0;
  for (int query = 0; query < q; ++query) {
    long long k, a, b;
    cin >> k >> a >> b;
    a = (a + succ) % MOD + 1;
    b = (b + succ) % MOD + 1;
    if (k == 1) {
      long long x = a, y = b;
      if (hull.count(x) > 0) {
        hull[x] = min(hull[x], y);
      } else {
        hull[x] = y;
      }
      auto it = hull.find(x);
      --it;
      while (should_del(it, hull)) {
        it = prev(hull.erase(it));
      }
      ++(++it);
      while (should_del(it, hull)) {
        it = hull.erase(it);
      }
      --it;
      if (should_del(it, hull)) {
        hull.erase(it);
      };
    } else {
      long long t = a, h = b;
      if (hull.rbegin()->first * t < h) {
        cout << "NO" << endl;
        continue;
      }
      auto it2 = hull.upper_bound(h / t);
      auto it1 = prev(it2);
      if ((it2->second - it1->second) * (h - it1->first * t) >
          (it2->first - it1->first) * (m - it1->second * t)) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        succ = query + 1;
      }
    }
  }
}
