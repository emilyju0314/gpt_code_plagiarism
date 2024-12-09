#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[100000];
  int n;
  int i;
  cin >> n;
  int j = 0, o = 0;
  for (i = 0; i < n; i++) {
    cin >> x[i];
    if (x[i] & 1)
      j = 1;
    else
      o = 1;
  }
  if (j && o) {
    sort(x, x + n);
    for (i = 0; i < n; i++) {
      cout << x[i] << ' ';
    }
  } else {
    for (i = 0; i < n; i++) {
      cout << x[i] << ' ';
    }
  }
  return 0;
}
