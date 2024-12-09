#include <bits/stdc++.h>
using namespace std;
const int B = 131;
const unsigned long long P = 1e9 + 7;
int n, m;
char s[200005];
unsigned long long t[26][200005], p[200005], a[26], b[26];
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) t[j][i] = 1;
    t[s[i] - 'a'][i] = 2;
    p[i] = p[i - 1] * B % P;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j <= n; j++) t[i][j] = (t[i][j - 1] * B + t[i][j]) % P;
  }
  while (m--) {
    int x, y, len;
    scanf("%d%d%d", &x, &y, &len);
    for (int i = 0; i < 26; i++) {
      a[i] = (t[i][x + len - 1] - t[i][x - 1] * p[len] % P + P) % P;
      b[i] = (t[i][y + len - 1] - t[i][y - 1] * p[len] % P + P) % P;
    }
    sort(a, a + 26);
    sort(b, b + 26);
    int flag = 1;
    for (int i = 0; i < 26; i++)
      if (a[i] != b[i]) {
        flag = 0;
        break;
      }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
