#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n + 2], c[n + 2];
  arr[0] = 0;
  arr[n + 1] = m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  int on = 0, off = 0;
  for (int i = n + 1; i >= 1; i--) {
    if (i % 2 == 1) {
      on += arr[i] - arr[i - 1];
      c[i] = on;
    } else {
      off += arr[i] - arr[i - 1];
      c[i] = off;
    }
  }
  int ans = 0, t = 0;
  for (int i = 1; i <= n; i += 2) {
    t += arr[i] - arr[i - 1];
    ans = max(ans, t + c[i + 1] - 1);
  }
  cout << max(ans, c[1]) << endl;
}
