#include <bits/stdc++.h>
using namespace std;
int max(int a[], int bd, int kt) {
  int vmax = bd;
  for (int i = bd + 1; i <= kt; i++) {
    if (a[i] > a[vmax]) vmax = i;
  }
  return vmax;
}
int main() {
  int n;
  int ans = 0;
  int best;
  cin >> n;
  int a[100 + 2];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (1) {
    best = max(a, 2, n);
    if (a[1] > a[best]) {
      cout << ans;
      return 0;
    }
    if (a[1] <= a[best]) {
      a[1] = a[1] + 1;
      ans = ans + 1;
      a[best] = a[best] - 1;
    }
  }
}
