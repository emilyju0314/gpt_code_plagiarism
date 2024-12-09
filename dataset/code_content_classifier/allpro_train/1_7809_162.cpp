#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n, i;
  cin >> T;
  while (T--) {
    cin >> n;
    if (n == 1)
      cout << "-1";
    else {
      for (i = 1; i < n; i++) cout << "9";
      cout << "4";
    }
    cout << endl;
  }
  return 0;
}
