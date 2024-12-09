#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
template <typename T, typename U>
bool compare(T x, U y) {
  return (abs(x - y) <= 1e-9);
}
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> sv(n + 1);
  int cnt = 1;
  for (int i = 2; i * i <= n; i++) {
    if (!sv[i]) {
      for (int j = i; j <= n; j += i) {
        if (!sv[j]) sv[j] = cnt;
      }
      cnt++;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (!sv[i]) {
      sv[i] = cnt;
      cnt++;
    }
    cout << sv[i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
}
