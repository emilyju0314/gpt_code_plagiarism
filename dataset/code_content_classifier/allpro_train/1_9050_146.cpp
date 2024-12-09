#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    int m;
    if ((n / 2) % 2 == 0) {
      m = n / 4;
    } else {
      m = (n / 4) + 1;
    }
    int ans = (n / 2) - m;
    if (n % 4 == 0) {
      cout << ans - 1;
    } else {
      cout << ans;
    }
  } else {
    cout << "0";
  }
}
