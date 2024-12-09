#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<char> > tab(n, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int e = 0; e < n; ++e) {
      if (i % 2 == 0) {
        if (e % 2 == 0) {
          tab[i][e] = 'W';
        } else
          tab[i][e] = 'B';
      } else {
        if (e % 2 == 0) {
          tab[i][e] = 'B';
        } else
          tab[i][e] = 'W';
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int e = 0; e < n; ++e) {
      cout << tab[i][e];
    }
    cout << "\n";
  }
  return 0;
}
