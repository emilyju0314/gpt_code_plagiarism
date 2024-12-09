#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, l, r;
  cin >> n >> l >> r;
  long a[n], c[n], b[n];
  for (long i = 0; i < n; i++) cin >> a[i];
  for (long i = 0; i < n; i++) {
    cin >> c[i];
    b[i] = a[i] + c[i];
  }
  long mini = b[0];
  for (long i = 0; i < n; i++) {
    if (b[i] < mini) mini = b[i];
  }
  long temp = mini - l;
  for (long i = 0; i < n; i++) {
    b[i] = b[i] - temp;
  }
  long maxi = b[0];
  for (long i = 0; i < n; i++) {
    if (b[i] > maxi) maxi = b[i];
  }
  if (maxi > r) {
    cout << -1 << endl;
    return 0;
  } else {
    for (long i = 0; i < n; i++) cout << b[i] << ' ';
    cout << endl;
  }
  return 0;
}
