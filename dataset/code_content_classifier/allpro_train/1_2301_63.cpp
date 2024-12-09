#include <bits/stdc++.h>
using namespace std;
map<int, bool> vis;
char ch[100];
int main() {
  int num[10];
  for (int i = 0; i < 9; i++) num[i] = 1990 + i;
  num[9] = 1989;
  int n;
  scanf("%d", &n);
  while (n--) {
    getchar();
    getchar();
    getchar();
    getchar();
    getchar();
    scanf("%s", ch);
    int len = strlen(ch);
    int ans = num[ch[len - 1] - '0'];
    int k = 100, t = ch[len - 1] - '0';
    vis.clear();
    vis[ans] = true;
    for (int i = len - 2; i >= 0; i--) {
      t = (ch[i] - '0') * (k / 10) + t;
      ans = ans / k * k + t;
      while (ans < 1989) ans += k;
      if (vis[ans]) ans += k;
      vis[ans] = true;
      k *= 10;
    }
    printf("%d\n", ans);
  }
  return 0;
}
