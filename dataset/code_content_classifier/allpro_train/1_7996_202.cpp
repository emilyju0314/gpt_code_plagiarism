#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ectr = 0, octr = 0;
  int le, lo;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      ectr++;
      le = i;
    } else if (x % 2 != 0) {
      octr++;
      lo = i;
    }
  }
  cout << (ectr > octr ? lo : le) << endl;
}
