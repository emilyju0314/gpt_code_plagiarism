#include <bits/stdc++.h>
using namespace std;
template <typename T>
T find_gcd(T a, T b) {
  while (b > 0) {
    swap(a, b);
    b %= a;
  }
  return a;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long m, d, w;
    cin >> m >> d >> w;
    w /= find_gcd(d - 1, w);
    long long mn = min(m, d), cnt = mn / w;
    cout << (2 * (mn - w) - w * (cnt - 1)) * cnt / 2 << '\n';
  }
  return 0;
}
