#include <bits/stdc++.h>
using namespace std;
int ans[1000][1000];
int main() {
  ios_base::sync_with_stdio(false);
  int k;
  cin >> k;
  int tmp = 1;
  ans[0][0] = 1;
  while (tmp <= k) {
    for (int i = 0; i < (1 << tmp); i++)
      for (int j = 0; j < (1 << tmp); j++) {
        if (i < (1 << tmp - 1) && j < (1 << tmp - 1)) continue;
        int mod1 = i % (1 << tmp - 1);
        int mod2 = j % (1 << tmp - 1);
        if (i < (1 << tmp - 1) || j < (1 << tmp - 1))
          ans[i][j] = ans[mod1][mod2];
        if (i >= (1 << tmp - 1) && j >= (1 << tmp - 1))
          ans[i][j] = 1 - ans[mod1][mod2];
      }
    tmp++;
  }
  for (int i = 0; i < (1 << k); i++, cout << endl)
    for (int j = 0; j < (1 << k); j++) cout << (ans[i][j] == 1 ? "+" : "*");
  return 0;
}
