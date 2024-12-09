#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int color[N], black[N], white[N], f[N][21], T, n, m;
char s[N];
inline int calc(int i, int j) { return (i - 1) * m + j; }
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      scanf("%s", s + 1);
      for (int j = 1; j <= m; j++) color[calc(i, j)] = (s[j] == '0' ? 0 : 1);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%s", s + 1);
      for (int j = 1; j <= m; j++) {
        int now = calc(i, j);
        if (s[j] == 'U')
          f[now][0] = now - m;
        else if (s[j] == 'D')
          f[now][0] = now + m;
        else if (s[j] == 'L')
          f[now][0] = now - 1;
        else
          f[now][0] = now + 1;
      }
    }
    n = n * m;
    for (int i = 1; i <= 20; i++)
      for (int j = 1; j <= n; j++) f[j][i] = f[f[j][i - 1]][i - 1];
    for (int i = 1; i <= n; i++) {
      int now = i;
      for (int j = 20; j >= 0; j--)
        if (n & (1 << j)) now = f[now][j];
      color[i] ? white[now] = 1 : black[now] = 1;
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
      if (black[i])
        ans++, cnt++, black[i] = white[i] = 0;
      else if (white[i])
        ans++, black[i] = white[i] = 0;
    cout << ans << " " << cnt << endl;
  }
  return 0;
}
