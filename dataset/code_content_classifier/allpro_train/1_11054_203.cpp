#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long n;
  int k;
  cin >> n >> k;
  long long ans = 0;
  if (k >= 4) {
    ans += 9 * n * (n - 1) * (n - 2) * (n - 3) / 24;
  }
  if (k >= 3) {
    ans += 2 * n * (n - 1) * (n - 2) / 6;
  }
  if (k >= 2) {
    ans += n * (n - 1) / 2;
  }
  ans += 1;
  cout << ans << endl;
}
