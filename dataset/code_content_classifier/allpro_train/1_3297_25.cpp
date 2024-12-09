#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int l = (n - k) / 2;
  for (int i = 1; i <= n; i++) {
    if (i % (l + 1) == 0) {
      cout << "0";
    } else
      cout << "1";
  }
  cout << endl;
  return 0;
}
