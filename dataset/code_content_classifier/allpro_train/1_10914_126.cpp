#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, x;
  cin >> n;
  bool flg = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x;
      if (flg == 0) {
        sum = sum + x;
      } else {
        sum = sum - x;
      }
    }
    flg = 1;
  }
  if (sum < 0) {
    cout << "No";
  } else {
    cout << "Yes";
  }
  return 0;
}
