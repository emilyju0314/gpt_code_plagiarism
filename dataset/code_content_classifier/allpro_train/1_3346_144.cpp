#include <bits/stdc++.h>
using namespace std;
int vis[26], tmp[26];
char op[11], s[111111];
int main(void) {
  int n, cnt = 0, num = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s %s", op, s);
    int len = strlen(s);
    if (op[0] == '!') {
      if (cnt >= 25) num++;
      for (int j = 0; j < 26; j++) tmp[j] = 0;
      for (int j = 0; j < len; j++) tmp[s[j] - 'a'] = 1;
      for (int j = 0; j < 26; j++)
        if (!vis[j] && !tmp[j]) vis[j] = 1, cnt++;
    } else if (op[0] == '.') {
      for (int j = 0; j < len; j++)
        if (!vis[s[j] - 'a']) vis[s[j] - 'a'] = 1, cnt++;
    } else {
      if (cnt >= 25 && i != n) num++;
      if (!vis[s[0] - 'a']) vis[s[0] - 'a'] = 1, cnt++;
    }
  }
  printf("%d\n", num);
  return 0;
}
