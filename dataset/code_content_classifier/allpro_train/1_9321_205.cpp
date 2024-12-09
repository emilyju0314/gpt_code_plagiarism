#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long i, j;
  long long a[n], b[n];
  int f = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] - b[i] != 0) {
      f = 1;
    }
  }
  int k = 0;
  if (f == 1) {
    cout << "rated";
    return 0;
  } else {
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        if (a[j] > a[i]) {
          k = 1;
          break;
        }
      }
    }
    if (k == 1) {
      cout << "unrated";
    } else
      cout << "maybe";
  }
  return 0;
}
