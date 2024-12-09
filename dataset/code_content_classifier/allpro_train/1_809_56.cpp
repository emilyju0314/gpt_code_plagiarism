#include <bits/stdc++.h>
using namespace std;
int n, arr[111111];
int main() {
  cin >> n;
  arr[0] = 0x3f3f3f3f;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int ii = n - i;
    if (arr[ii] < arr[ii - 1]) {
      ans = i;
      break;
    }
  }
  ans = n - ans - 1;
  cout << ans << endl;
  return 0;
}
