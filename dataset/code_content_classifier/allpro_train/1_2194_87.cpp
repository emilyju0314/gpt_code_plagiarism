#include <bits/stdc++.h>
using namespace std;
const int b = 3e4;
int a[b];
int n, ans = 0, x = 0, y = 0, z = 0;
void taxi() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int ez;
    cin >> ez;
    if (ez == 4)
      ans++;
    else if (ez == 3)
      z++;
    else if (ez == 2)
      y++;
    else if (ez == 1)
      x++;
  }
  ans += min(x, z);
  int c = min(x, z);
  x -= c;
  z -= c;
  ans += y / 2;
  y = y % 2;
  ans += min(y, x / 2);
  c = min(y, x / 2);
  y -= c;
  x -= 2 * c;
  if (y == 1 && x >= 0) {
    ans++;
    x--;
  }
  ans += ceil(x / 4.0);
  ans += z;
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), srand(time(0));
  taxi();
  return 0;
}
