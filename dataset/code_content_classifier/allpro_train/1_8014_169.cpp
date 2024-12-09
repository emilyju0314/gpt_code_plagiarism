#include <bits/stdc++.h>
using namespace std;
int travel(int minn, int maxx, int k) {
  if (k <= minn)
    return maxx - k;
  else if (k >= maxx)
    return k - minn;
  return maxx - minn + min(maxx - k, k - minn);
}
void solve() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  int minn = a[0];
  int maxx = a[n - 2];
  int answer = travel(minn, maxx, k);
  answer = min(answer, travel(a[1], a[n - 1], k));
  cout << answer << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
