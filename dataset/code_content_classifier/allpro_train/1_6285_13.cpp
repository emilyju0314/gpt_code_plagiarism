#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 1;
  int k = n;
  int l = 9;
  int logs = 0;
  while (k != 0) {
    logs++;
    l = k;
    k /= 10;
  }
  if (logs == 1)
    cout << 1;
  else if (l == 9) {
    for (int i = 0; i < logs; i++) ans *= 10;
    cout << ans - n;
  } else {
    for (int i = 0; i < logs - 1; i++) ans *= 10;
    ans *= l + 1;
    cout << ans - n;
  }
  return 0;
}
