#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; i++) {
      cin >> tab[i];
    }
    long long x = 1;
    for (int i = n - 1; i >= 1; i--) {
      if (tab[i] == 1 && tab[i - 1] == 1) {
        x += 5;
        continue;
      }
      if (tab[i] == 0 && tab[i - 1] == 0) {
        x = -1;
        break;
      }
      if (tab[i] == 1) {
        x += 1;
      }
    }
    if (tab[0] == 1 && x != -1) {
      x += 1;
    }
    cout << x << endl;
  }
  return 0;
}
