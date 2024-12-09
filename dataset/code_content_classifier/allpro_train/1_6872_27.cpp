#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    char s[9][9];
    int x1, y1, x2, y2;
    int flag = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        cin >> s[i][j];
        if (s[i][j] == 'K' && flag == 0) {
          x1 = i;
          y1 = j;
          flag = 1;
        }
        if (s[i][j] == 'K' && flag == 1) {
          x2 = i;
          y2 = j;
        }
      }
      getchar();
    }
    if ((x1 - x2) % 4 == 0 && (y1 - y2) % 4 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
