#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char a[100];
  int x = 1;
  int ans = 0;
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (flag && x + a[i] - '0' == 2) {
      x = 1;
      ans += 1;
    } else
      flag = 0;
  }
  if (ans == n)
    cout << n;
  else
    cout << ans + 1;
}
