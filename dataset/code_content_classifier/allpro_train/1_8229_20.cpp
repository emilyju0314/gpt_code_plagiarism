#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  if (k > 2 && k <= (n + (n - 1))) {
    if (k > n) {
      long long diff = k - n;
      diff--;
      if (k % 2 == 0) {
        long long result = (k / 2) - 1;
        cout << abs(diff - result) << endl;
        return;
      } else {
        long long result = (k / 2);
        cout << abs(result - diff) << endl;
        return;
      }
    } else {
      if (k % 2 == 0) {
        long long result = (k / 2) - 1;
        cout << result << endl;
        return;
      } else {
        long long result = (k / 2);
        cout << result << endl;
        return;
      }
    }
  } else {
    cout << 0 << endl;
    return;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
