#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int arr[2 * n];
    for (int i = 0; i < 2 * n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + 2 * n);
    cout << (arr[n] - arr[n - 1]) << endl;
  }
  return 0;
}
