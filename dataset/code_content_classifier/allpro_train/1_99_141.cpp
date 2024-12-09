#include <bits/stdc++.h>
using namespace std;
int t, a, b;
int m[1001], n[1001], flag;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    flag = 0;
    cin >> a >> b;
    for (int x = 0; x < a; x++) cin >> m[x];
    for (int y = 0; y < b; y++) cin >> n[y];
    for (int z = 0; z < a; z++) {
      if (flag == 1) break;
      for (int r = 0; r < b; r++) {
        if (flag == 1) break;
        if (m[z] == n[r]) {
          cout << "YES" << endl << 1 << " " << m[z] << endl;
          flag = 1;
        }
      }
    }
    if (flag == 0) cout << "NO" << endl;
  }
}
