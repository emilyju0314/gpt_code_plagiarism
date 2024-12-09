#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, l = 0;
  int a[100];
  cin >> n;
  cin >> m;
  for (x = 0; x < n; x++) {
    cin >> a[x];
  }
  for (x = 0; x < n; x++) {
    if (ceil((float)a[x] / (float)m) >= ceil((float)a[l] / (float)m)) l = x;
  }
  cout << l + 1;
  return 0;
}
