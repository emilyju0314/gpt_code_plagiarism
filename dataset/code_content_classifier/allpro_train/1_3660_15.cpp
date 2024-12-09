#include <bits/stdc++.h>
using namespace std;
int test, n, k;
int a[200001];
int main() {
  cin >> test;
  while (test--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cs = 0, ce = 0, ans = 0;
    int i = 0;
    while (a[i] != 1) {
      cs++;
      i++;
    }
    i = n - 1;
    while (a[i] != 1) {
      ce++;
      i--;
    }
    for (int j = cs; j <= i; j++) {
      if (a[j] == 0) {
        ans++;
      }
    }
    cout << ans;
    cout << "\n";
  }
  return 0;
}
