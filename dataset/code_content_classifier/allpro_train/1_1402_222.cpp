#include <bits/stdc++.h>
using namespace std;
const int MOD = 10e9 + 7;
const int INF = 10e9;
template <typename T>
std::ostream& operator<<(ostream& os, const vector<T>& v) {
  for (T const& i : v) {
    os << i << " ";
  }
  os << endl;
  return os;
}
template <class T>
inline T gcd(T x, T y) {
  if (!y) return x;
  return gcd(y, x % y);
}
vector<int> sieve(int n) {
  vector<bool> s(n, true);
  for (int i = 2; i * i <= n; i++)
    if (s[i])
      for (int j = 2 * i; j < n; j += i) s[j] = false;
  vector<int> primes;
  for (int i = 0; i < n; i++)
    if (s[i]) primes.push_back(s[i]);
  return primes;
}
int main() {
  int t;
  cin >> t;
  for (auto __ = 0; __ < t; __++) {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto& i : ar) cin >> i;
    int lowest = INF;
    vector<int> lower(n);
    for (int i = n - 1; i >= 0; i--) {
      if (ar[i] < lowest) {
        lowest = ar[i];
      }
      lower[i] = lowest;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
      if (ar[i] > lower[i]) count++;
    cout << count << endl;
  }
  return 0;
}
