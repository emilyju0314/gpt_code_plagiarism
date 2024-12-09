#include <bits/stdc++.h>
using namespace std;
long long int n, m;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m;
    if (m < 10) {
      cout << (m - 1) * 10 + 1;
    } else {
      if (m < 100) {
        cout << ((m % 10) - 1) * 10 + 3;
      } else {
        if (m < 1000) {
          cout << ((m % 10) - 1) * 10 + 6;
        } else {
          cout << ((m % 10) - 1) * 10 + 10;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
