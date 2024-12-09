#include <bits/stdc++.h>
using namespace std;
int k, all, re[10001], flag[10001];
char str[201];
char s[10002];
void prt() {
  if (all == 0) {
    puts("/");
    return;
  }
  for (int i = 0; i < all; i++) {
    int st = flag[i];
    int en = re[i];
    printf("/");
    for (int j = st; j <= en - 1; j++) {
      printf("%c", s[j]);
    }
  }
  printf("/\n");
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    if (strcmp(str, "pwd") == 0)
      prt();
    else {
      scanf("%s", str);
      int len = strlen(str);
      if (str[0] == '/') {
        k = 0;
        all = 0;
      }
      for (int i = 0; i < len;) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          flag[all] = ++k;
          while (i < len && str[i] != '/') {
            s[k++] = str[i++];
          }
          re[all++] = k;
        } else if (str[i] == '.') {
          i += 2;
          all--;
        } else
          i++;
      }
    }
  }
  return 0;
}
