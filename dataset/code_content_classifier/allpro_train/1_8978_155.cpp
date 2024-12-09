#include <bits/stdc++.h>
using namespace std;
int change(int cnt, int a[], int n) {
  int b[n], i, d;
  for (i = 0; i < n; i++) b[i] = a[i];
  d = b[1] - b[0];
  for (i = 2; i < n; i++) {
    if (b[i] - b[i - 1] == d)
      continue;
    else if ((b[i] + 1) - b[i - 1] == d) {
      cnt++;
      b[i]++;
    } else if ((b[i] - 1) - b[i - 1] == d) {
      cnt++;
      b[i]--;
    } else
      return INT_MAX;
  }
  return cnt;
}
int main() {
  int i, j, n, c = INT_MAX, dif;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  if (n <= 2)
    cout << 0 << endl;
  else {
    for (i = -1; i <= 1; i++) {
      for (j = -1; j <= 1; j++) {
        a[0] += i;
        a[1] += j;
        dif = change(abs(i) + abs(j), a, n);
        if (dif < c) c = dif;
        a[0] -= i;
        a[1] -= j;
      }
    }
    if (c == INT_MAX)
      cout << -1;
    else
      cout << c << endl;
  }
  return 0;
}
