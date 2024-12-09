#include <bits/stdc++.h>
using namespace std;
int main() {
  bool a[1000000] = {0};
  int b[100000];
  int n, m, x;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> b[i];
  a[b[n - 1]] = 1;
  b[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[b[i]] == 0) {
      a[b[i]] = 1;
      b[i] = b[i + 1] + 1;
    } else {
      b[i] = b[i + 1];
    }
  }
  while (m--) {
    cin >> x;
    cout << b[x - 1] << endl;
  }
  return 0;
}
