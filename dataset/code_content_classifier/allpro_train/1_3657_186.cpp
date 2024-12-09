#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, k;
  cin >> n;
  int a[n], b[n];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= n; i++) {
    k = a[i];
    b[k] = i;
  }
  for (i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
}
