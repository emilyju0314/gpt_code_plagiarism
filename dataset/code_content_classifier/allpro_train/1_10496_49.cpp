#include <bits/stdc++.h>
using namespace std;
bool flag = 0, flag1 = 0, flag2 = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long int ans = 0;
    long long int x = x2 - x1 + 1;
    long long int y = y2 - y1 + 1;
    ans += y + ((x - 2) * (y - 1));
    if (x == 1 || y == 1) ans = 1;
    cout << ans << "\n";
  }
}
