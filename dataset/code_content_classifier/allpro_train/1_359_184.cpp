#include <bits/stdc++.h>
using namespace std;
long long int dx[] = {-1, +1, 0, 0, +1, -1, +1, -1};
long long int dy[] = {0, 0, -1, +1, +1, +1, -1, -1};
const long long int mx = 1e5 + 123;
const long long int MOD = 1e9 + 7;
const long long int INF = LLONG_MAX;
template <class T>
T power(T a, T b) {
  a %= MOD;
  if (!a) return 0;
  T p = 1;
  while (b > 0) {
    if (b & 1) {
      p *= a;
      p %= MOD;
    }
    a *= a;
    a %= MOD;
    b = b >> 1;
  }
  return p;
}
template <class T>
void print(vector<T> &v) {
  for (T u : v) {
    cout << u << " ";
  }
  cout << endl;
}
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long int t, a, i;
  cin >> t;
  while (t--) {
    cin >> a;
    vector<long long int> v;
    long long int b[a], c[a], d[a], x[a];
    for (long long int i = 0; i < a; i++) cin >> b[i];
    for (long long int i = 0; i < a; i++) cin >> c[i];
    for (long long int i = 0; i < a; i++) cin >> d[i];
    for (long long int i = 0; i < a; i++) {
      if (i == 0)
        v.push_back(b[i]);
      else if (i == a - 1) {
        if (b[i] != v[0] && v[i - 1] != b[i])
          v.push_back(b[i]);
        else if (c[i] != v[0] && v[i - 1] != c[i])
          v.push_back(c[i]);
        else
          v.push_back(d[i]);
      } else {
        if (c[i] != v[i - 1])
          v.push_back(c[i]);
        else if (d[i] != v[i - 1]) {
          v.push_back(d[i]);
        } else
          v.push_back(b[i]);
      }
    }
    print(v);
  }
  return 0;
}
