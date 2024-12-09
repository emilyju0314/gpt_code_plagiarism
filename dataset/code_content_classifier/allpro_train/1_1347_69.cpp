#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, l;
  cin >> a >> b >> c >> l;
  long long int ans = 0;
  long long int i, j, k;
  for (i = 0; i <= l; i++) {
    long long int hehe = (b + c - a + i) / 2;
    if ((b + c - a + i) % 2 == 1) hehe++;
    long long int haha = (a + b - c + i) / 2;
    if ((a + b - c + i) % 2 == 1) haha++;
    long long int hehehaha = (c + a - b + i) / 2;
    if ((c + a - b + i) % 2 == 1) hehehaha++;
    if (hehe <= 0 || haha <= 0 || hehehaha <= 0) continue;
    ans += (i + 1) * (i + 2) / 2;
    if (i >= hehe) ans -= (i - hehe + 1) * (i - hehe + 2) / 2;
    if (i >= haha) ans -= (i - haha + 1) * (i - haha + 2) / 2;
    if (i >= hehehaha) ans -= (i - hehehaha + 1) * (i - hehehaha + 2) / 2;
    if (i >= hehe + haha)
      ans += (i - hehe - haha + 1) * (i - haha - hehe + 2) / 2;
    if (i >= hehe + hehehaha)
      ans += (i - hehe - hehehaha + 1) * (i - hehehaha - hehe + 2) / 2;
    if (i >= haha + hehehaha)
      ans += (i - haha - hehehaha + 1) * (i - haha - hehehaha + 2) / 2;
    if (i >= hehe + haha + hehehaha)
      ans += (i - haha - hehehaha - hehe + 1) *
             (i - haha - hehe - hehehaha + 2) / 2;
  }
  cout << ans << endl;
}
