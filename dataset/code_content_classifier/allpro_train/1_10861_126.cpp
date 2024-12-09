#include <bits/stdc++.h>
const int oo = 0x3f3f3f3f;
using namespace std;
inline int read() {
  int x = 0, f = 1, hhh = getchar();
  while (!isdigit(hhh)) {
    if (hhh == '-') f = -1;
    hhh = getchar();
  }
  while (isdigit(hhh)) {
    x = x * 10 + hhh - '0';
    hhh = getchar();
  }
  return x * f;
}
const int c[] = {0, 1, 2, 3, 4, 6, 12};
const int r[] = {0, 12, 6, 4, 3, 2, 1};
char a[100][100];
bool ans[10];
int main() {
  int T = read();
  while (T--) {
    memset(a, 0, sizeof(a));
    memset(ans, false, sizeof(ans));
    string s;
    cin >> s;
    for (int cas = (1); cas <= (6); ++cas) {
      int now = 0;
      for (int i = (1); i <= (c[cas]); ++i)
        for (int j = (1); j <= (r[cas]); ++j) {
          a[i][j] = s[now++];
        }
      for (int i = (1); i <= (r[cas]); ++i) {
        bool flag = false;
        for (int j = (1); j <= (c[cas]); ++j) {
          if (a[j][i] == 'O') {
            flag = true;
            break;
          }
        }
        if (!flag) {
          ans[cas] = true;
          break;
        }
      }
    }
    int ret = 0;
    for (int i = (1); i <= (6); ++i) ret += (ans[i] == true);
    printf("%d ", ret);
    for (int i = (1); i <= (6); ++i)
      if (ans[i] == true) printf("%dx%d ", c[i], r[i]);
    puts("");
  }
  return 0;
}
