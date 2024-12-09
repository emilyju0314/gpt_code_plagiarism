#include <bits/stdc++.h>
using namespace std;
int main() {
  int tst;
  cin >> tst;
  while (tst--) {
    int n;
    cin >> n;
    long long int arr[n];
    bool f = false;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] != arr[i - 1] && i > 0) f = true;
    }
    if (!f)
      cout << -1 << "\n";
    else {
      long long int mx = *max_element(arr, arr + n);
      for (int i = 0; i < n; i++) {
        if (arr[i] == mx && ((arr[i] != arr[i + 1] && i < n - 1) ||
                             (arr[i] != arr[i - 1] && i > 0))) {
          cout << i + 1 << "\n";
          break;
        }
      }
    }
  }
  return 0;
}
