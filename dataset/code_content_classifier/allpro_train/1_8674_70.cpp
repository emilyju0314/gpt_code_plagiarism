#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 0;
    int l = 1;
    for (int i = 0; i < n && l >= 0; i++) {
      if (l >= arr[i]) {
        ans++;
        l = 1;
      } else {
        l++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
