#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
template <class T>
void _print(T x) {
  cout << x;
}
template <class T>
void _print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << ", ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << ", ";
  }
  cout << "]";
}
template <class T>
void _print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << ", ";
  }
  cout << "]";
}
template <class T, class V>
void _print(pair<T, V> p) {
  cout << "{";
  _print(p.first);
  cout << ",";
  _print(p.second);
  cout << "}";
}
template <class T, class V>
void _print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
vector<bool> _generatePrimes() {
  ll n = 1e6 + 5;
  vector<bool> prime(n, true);
  prime[0] = prime[1] = false;
  for (ll i = 2; i < n; ++i) {
    if (prime[i]) {
      for (ll j = i * i; j < n; j += i) prime[j] = false;
    }
  }
  return prime;
}
void solve() {
  ll n;
  cin >> n;
  if (n & 1)
    cout << n / 2;
  else {
    ll cur = 1;
    while (cur * 2 <= n) {
      cur *= 2;
    }
    n = n - cur;
    ;
    if (n == 0)
      cout << 0;
    else
      cout << n / 2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
