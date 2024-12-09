#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n][n];
  int res = 0;
  int r = (n - 1) / 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      if (i == j || i + j == n - 1) {
        res += arr[i][j];
      } else if (j == r)
        res += arr[i][j];
      else if (i == r)
        res += arr[i][j];
      else
        continue;
    }
  }
  cout << res;
  return 0;
}
