#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (5 - arr[i] >= k) {
      cnt++;
    }
  }
  int ans = cnt / 3;
  cout << ans;
}
