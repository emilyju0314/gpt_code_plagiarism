#include <bits/stdc++.h>
using namespace std;
void fast_in_out() {
  std::ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
}
vector<int> v;
int main() {
  fast_in_out();
  int n, t, c;
  cin >> n >> t >> c;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > t) v.push_back(i);
  }
  v.push_back(n);
  int ans = 0, p = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] - p >= c) ans += v[i] - c - p + 1;
    p = v[i] + 1;
  }
  cout << ans << endl;
  return 0;
}
