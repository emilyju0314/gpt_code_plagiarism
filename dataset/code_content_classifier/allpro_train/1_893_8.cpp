#include <bits/stdc++.h>
using namespace ::std;
void solve() {
  double s = 0;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n % 2) {
    a.push_back(0);
    n++;
  }
  sort(a.begin(), a.end());
  for (int i = n - 1; i > 0; i -= 2) {
    s += (a[i] * a[i] - a[i - 1] * a[i - 1]) * 3.14159265358979323846;
  }
  cout << fixed << setprecision(8) << s << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
