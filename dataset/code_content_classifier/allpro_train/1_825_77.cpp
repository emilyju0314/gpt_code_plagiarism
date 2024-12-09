#include <bits/stdc++.h>
using namespace std;
const int maxn = 0;
int main() {
  int ans = 15;
  int n, x;
  cin >> n;
  while (n--) {
    cin >> x;
    if (x > ans)
      break;
    else
      ans = min(90, x + 15);
  }
  cout << ans << endl;
  return 0;
}
