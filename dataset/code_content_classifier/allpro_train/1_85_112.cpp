#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, ma = -1;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    sum = sum + ar[i];
    ma = max(ma, ar[i]);
  }
  int res = 2 * sum / n;
  res = max(res, ma);
  if (n * res > 2 * sum) {
    cout << res;
  } else {
    cout << res + 1;
  }
}
