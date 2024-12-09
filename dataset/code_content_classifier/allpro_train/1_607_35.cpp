#include <bits/stdc++.h>
using namespace std;
int n, a[20];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < (1 << n); i++) {
    int sum = 0;
    for (int j = 0; j < 16; j++) {
      if (((1 << j) & i))
        sum += a[j];
      else
        sum -= a[j];
    }
    if (sum % 360 == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
