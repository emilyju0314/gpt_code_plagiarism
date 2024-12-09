#include <bits/stdc++.h>
using namespace std;
int solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}
const int N = 2e5;
int a[N];
vector<int> v;
int solve() {
  int n;
  cin >> n;
  a[0] = -1;
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }
  int i = n - 1;
  while (i > -1) {
    v.push_back(i + 1);
    i = a[i] - 1;
  }
  reverse(v.begin(), v.end());
  for (auto i : v) cout << i << ' ';
  cout << '\n';
  return 0;
}
