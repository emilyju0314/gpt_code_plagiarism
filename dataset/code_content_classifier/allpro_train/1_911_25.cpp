#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[n + 1], i, maxi = -1;
    for (i = 1; i <= n; i++) {
      cin >> arr[i];
      maxi = max(maxi, arr[i]);
    }
    int size[k + 1];
    if (k >= n) {
      cout << maxi << endl;
      return 0;
    }
    for (i = 1; i <= 2 * k - n; i++) {
      size[k - i + 1] = arr[n - i + 1];
      maxi = max(maxi, size[k - i + 1]);
    }
    for (i = 1; i <= n - k; i++) {
      size[i] = arr[i] + arr[2 * n - 2 * k - i + 1];
      maxi = max(maxi, size[i]);
    }
    cout << maxi << endl;
  }
}
