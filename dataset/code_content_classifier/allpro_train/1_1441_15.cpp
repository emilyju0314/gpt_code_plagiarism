#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int brr[100000];
int crr[100000];
int main() {
  int n, l;
  cin >> n >> l;
  int flag = 0;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int j = 0; j < n; j++) cin >> brr[j];
  for (int i = 0; i < n; i++) {
    crr[arr[i]] = 1;
  }
  int s = arr[0];
  int x;
  int fans = 1;
  int z = 1;
  if ((l - arr[n - 1] - 1) + (arr[0] - 0 + 1) == brr[1] - brr[0]) {
    s = arr[n - 1];
    for (int i = 1; i < n; i++) {
      int diff = brr[i] - brr[i - 1];
      s = (diff + s) % l;
      if (crr[s] == 0) {
        fans = 0;
        break;
      }
    }
    if (fans == 1) flag = 1;
  }
  z = 1;
  while (z < n && flag == 0) {
    int f2 = 1;
    int f3 = 1;
    while (z < n) {
      if (arr[z] - arr[z - 1] == brr[1] - brr[0]) {
        f2 = 0;
        break;
      }
      z++;
    }
    if (f2 == 0) {
      s = arr[z - 1];
      for (int i = 1; i < n && f3; i++) {
        int diff = brr[i] - brr[i - 1];
        s = (diff + s) % l;
        if (crr[s] == 0) {
          f3 = 0;
          break;
        }
      }
      if (f3) {
        z = n;
        flag = 1;
      }
    }
    z++;
  }
  if (n == 1)
    cout << "YES";
  else if (flag == 1)
    cout << "YES";
  else
    cout << "NO";
}
