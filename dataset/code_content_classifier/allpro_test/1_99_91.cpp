#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int x, n;
  cin >> x >> n;
  long long int cnt = 1, ans = 0;
  vector<long long int> v;
  long long int current = x;
  for (long long int i = 0; i < 4; i++) {
    long long int minimum = i + 1;
    if (current & 1) {
      current = current + minimum;
    } else {
      current = current - minimum;
    }
    v.push_back(current);
  }
  long long int t = n % 4;
  if (t == 0 || t == 2) {
    if (t == 0) {
      t = t + 4;
    }
    cout << v[t - 1];
  } else {
    if (t == 1) {
      n--;
      long long int de = n / 4.0;
      if (x & 1) {
        cout << v[t - 1] + de * 4;
      } else {
        cout << v[t - 1] - de * 4;
      }
    } else {
      n--;
      long long int de = n / 4.0;
      if (x & 1) {
        cout << v[t - 1] - de * 4;
      } else {
        cout << v[t - 1] + de * 4;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
