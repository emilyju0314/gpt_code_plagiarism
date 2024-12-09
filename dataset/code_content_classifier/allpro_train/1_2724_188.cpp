#include <bits/stdc++.h>
int main(void) {
  long long int m, i, l, count[100008] = {0}, e, swap;
  char ch[200006];
  scanf("%s\n", ch);
  l = strlen(ch);
  scanf("%I64d\n", &m);
  while (m--) {
    scanf("%I64d", &e);
    count[e]++;
  }
  long long int s = 0;
  for (i = 1; i <= l / 2; i++) {
    s += count[i];
    count[i] = s;
  }
  for (i = 1; i <= l / 2; i++) {
    if (count[i] % 2 == 1) {
      swap = ch[l - i];
      ch[l - i] = ch[i - 1];
      ch[i - 1] = swap;
    }
  }
  printf("%s\n", ch);
  return 0;
}
