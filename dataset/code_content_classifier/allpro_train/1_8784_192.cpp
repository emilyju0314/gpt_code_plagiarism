#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  string a[4000], b[4000], c[4000];
  cin >> n;
  cin >> m;
  for (int i = 0; i <= m - 1; i++) {
    cin >> a[i];
    cin >> b[i];
  }
  for (int i = 0; i <= n - 1; i++) {
    cin >> c[i];
    for (int j = 0; j <= m - 1; j++) {
      if (c[i] == a[j]) {
        if (b[j].length() < a[j].length()) {
          cout << b[j];
          cout << " ";
        } else if (b[j].length() > a[j].length()) {
          cout << a[j];
          cout << " ";
        } else {
          cout << a[j];
          cout << " ";
        }
        break;
      }
    }
  }
  return 0;
}
