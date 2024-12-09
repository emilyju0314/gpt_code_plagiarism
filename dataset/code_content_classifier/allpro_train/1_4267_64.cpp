#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int te;
  cin >> te;
  while (te--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b * c) {
      cout << -1 << '\n';
      continue;
    }
    long long val = a;
    long long maxi = a / (b * d);
    val += a * maxi;
    val -= b * d * (maxi * (maxi + 1)) / 2;
    cout << val << '\n';
  }
}
