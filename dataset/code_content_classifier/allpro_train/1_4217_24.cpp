#include <bits/stdc++.h>
int s[26];
int t;
int best = 26;
char cmd[26][100];
char b[26][100];
void f(int pos) {
  int i, j, k, k1;
  if (pos >= best) {
    return;
  }
  for (i = 0; i < pos; i++) {
    for (j = 0; j < pos; j++) {
      if (!s[j]) continue;
      for (k1 = 0; k1 < 8; k1++) {
        int k;
        int v;
        if (k1 < 4) {
          k = 1 << k1;
          v = s[i] + s[j] * k;
          sprintf(cmd[pos], "lea e%cx, [e%cx + %d*e%cx]", pos + 'a', i + 'a', k,
                  j + 'a');
        } else {
          k = 1 << (k1 - 4);
          v = s[j] * k;
          sprintf(cmd[pos], "lea e%cx, [%d*e%cx]", pos + 'a', k, j + 'a');
        }
        s[pos] = v;
        if (v == t) {
          best = pos;
          memcpy(b, cmd, sizeof(cmd));
          return;
        }
        int z, found = 0;
        for (z = 0; z < pos; z++) {
          if (s[z] == v) {
            found = 1;
            break;
          }
        }
        if (!found) f(pos + 1);
        s[pos] = 0;
      }
    }
  }
}
int main() {
  int n, i;
  scanf("%d", &n);
  memset(s, 0, sizeof(s));
  s[0] = 1;
  t = n;
  if (t == 1) {
    printf("0\n");
    return 0;
  }
  f(1);
  printf("%d\n", best);
  for (i = 1; i <= best; i++) {
    printf("%s\n", b[i]);
  }
  return 0;
}
