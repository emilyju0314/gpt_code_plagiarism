#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, ans = 0, temp = 0;
  char ch;
  cin >> n >> d;
  for (int i = 0; i < d; i++) {
    int win = 0;
    for (int j = 0; j < n; j++) {
      cin >> ch;
      if (ch == '0') {
        win = 1;
      }
    }
    if (win == 1) {
      temp++;
      ans = max(ans, temp);
    } else {
      temp = 0;
    }
  }
  cout << ans;
}
