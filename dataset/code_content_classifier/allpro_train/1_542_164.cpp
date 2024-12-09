#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int m;
  cin >> m;
  int *arr1 = new int[m];
  for (int i = 0; i < m; i++) cin >> arr1[i];
  int maxi = 0, total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int m = arr1[j] % arr[i];
      int d = arr1[j] / arr[i];
      if (m == 0) {
        if (d > maxi) {
          total = 1;
          maxi = d;
        } else if (d == maxi)
          total++;
      }
    }
  }
  cout << total;
  return 0;
}
