#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O3")
using ld = long double;
const long long int mod = 1000000007;
const long long int inf = 1000000000000000000;
const long long int rk = 256;
const ld PI = 3.141592653589793;
ostream& operator<<(ostream& os, pair<long long int, long long int> const& x) {
  os << x.first << "," << x.second;
  return os;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> const& x) {
  os << "{ ";
  for (auto& y : x) os << y << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, set<T> const& x) {
  os << "{ ";
  for (auto& y : x) os << y << " ";
  return os << "}";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
  os << "{ ";
  for (auto& y : x) os << y << " ";
  return os << "}";
}
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
  return os << "[ " << p.first << ", " << p.second << "]";
}
bool sortinrev(const pair<long long int, long long int>& a,
               const pair<long long int, long long int>& b) {
  return (a.first > b.first);
}
void func(queue<long long int> q) {
  while (!q.empty()) {
    cout << " " << q.front();
    q.pop();
  }
  cout << '\n';
}
long long int modularexpo(long long int x, long long int n, long long int mod) {
  long long int res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n = n / 2;
  }
  return res;
}
int main() {
  long long int n, m, f = 0;
  cin >> n >> m;
  while (true) {
    if (f == 0) {
      if (n >= 2 && m >= 2) {
        n -= 2;
        m -= 2;
      } else if (n >= 1 && m >= 12) {
        n -= 1;
        m -= 12;
      } else if (m >= 22)
        m -= 22;
      else
        break;
      f = 1 ^ f;
    } else {
      if (m >= 22)
        m -= 22;
      else if (n >= 1 && m >= 12) {
        n -= 1;
        m -= 12;
      } else if (n >= 2 && m >= 2) {
        n -= 2;
        m -= 2;
      } else
        break;
      f = 1 ^ f;
    }
  }
  if (f == 1)
    cout << "Ciel" << '\n';
  else
    cout << "Hanako" << '\n';
  return 0;
}
