#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, d, h;
  cin >> n >> d >> h;
  if (h == 1 && d == 1) {
    if (n > 2) {
      cout << "-1";
      return 0;
    }
  }
  if (d > 2 * h || n < d + 1) {
    cout << "-1";
    return 0;
  }
  long long i, j;
  long long cnt = 0;
  for (i = 1; i <= h; i++) {
    cout << i << " " << i + 1 << endl;
    cnt++;
  }
  long long k, p = 1;
  if (d > h) {
    k = 1;
  } else {
    k = h - d + 2;
  }
  for (j = i + 1; j < i + 1 + d - h; j++) {
    cout << p << " " << j << endl;
    p = j;
    cnt++;
  }
  while (cnt < n - 1) {
    cout << k << " " << j << endl;
    cnt++;
    j++;
  }
}
