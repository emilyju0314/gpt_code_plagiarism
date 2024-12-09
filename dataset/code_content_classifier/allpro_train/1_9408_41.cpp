#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr[110][110];
  memset(arr, 0, sizeof(arr));
  if (n * n < k) {
    cout << "-1";
    return 0;
  }
  int ok = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (arr[i][j]) continue;
      if (k == 0) {
        ok = 1;
        break;
      }
      if (i == j) {
        arr[i][j] = 1;
        k--;
      } else {
        if (k >= 2) {
          arr[i][j] = 1;
          arr[j][i] = 1;
          k -= 2;
        }
      }
    }
    if (ok) break;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j != n)
        cout << arr[i][j] << ' ';
      else
        cout << arr[i][j];
    }
    if (i != n) cout << endl;
  }
  return 0;
}
