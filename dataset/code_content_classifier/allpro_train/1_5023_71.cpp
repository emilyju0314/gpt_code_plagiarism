#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int arr[50] = {};
int main() {
  ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  ;
  int n, w, b;
  cin >> n >> w >> b;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  int l = 1, r = n, sum = 0;
  while (l <= r) {
    if (arr[l] != 2 && arr[r] != 2) {
      if (arr[l] != arr[r]) return cout << -1 << "\n", 0;
      ;
    } else {
      if (!arr[l] || !arr[r])
        sum += w;
      else if (arr[l] == 1 || arr[r] == 1)
        sum += b;
      else {
        if (l == r)
          sum += min(w, b);
        else
          sum += (2 * min(w, b));
      }
    }
    ++l, --r;
  }
  cout << sum << "\n";
  return 0;
}
