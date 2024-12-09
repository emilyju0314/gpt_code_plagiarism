#include <bits/stdc++.h>
using namespace std;
char s[110000];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  int now = 0;
  for (int i = 0; i < len; i++) {
    if (now < 26) {
      if (s[i] <= char('a' + now)) {
        s[i] = char('a' + now);
        now++;
      }
    }
  }
  if (now >= 26) {
    for (int i = 0; i < len; i++) printf("%c", s[i]);
  } else
    printf("-1\n");
}
