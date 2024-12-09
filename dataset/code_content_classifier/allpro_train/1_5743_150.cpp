#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, i;
  cin >> n >> x;
  long long int a[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long int ind = -1, mn = 1e16;
  for (i = x; i > 0; i--) {
    if (a[i] < mn) {
      mn = a[i];
      ind = i;
    }
  }
  for (i = n; i > x; i--) {
    if (a[i] < mn) {
      mn = a[i];
      ind = i;
    }
  }
  long long int cnt = 0;
  if (ind > x) {
    for (i = ind + 1; i <= n; i++) {
      cnt++;
      a[i]--;
    }
    for (i = 1; i <= x; i++) {
      cnt++;
      a[i]--;
    }
  } else {
    for (i = ind + 1; i <= x; i++) {
      cnt++;
      a[i]--;
    }
  }
  x = a[ind];
  cnt += (n * x);
  for (i = 1; i <= n; i++) {
    if (i == ind) {
      cout << cnt << " ";
      continue;
    }
    cout << a[i] - x << " ";
  }
  cout << "\n";
}
