#include <bits/stdc++.h>
int main() {
  int n, i, p = -1, t;
  int a[101], c[101] = {0};
  char s[101], f = 66;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", a + i);
    c[a[i]]++;
  }
  for (i = 0; i < n; i++) {
    if ((t = c[a[i]]) == 1) {
      if (f == 66)
        f = 65;
      else
        f = 66;
      s[i] = f;
    } else {
      s[i] = 65;
      if (t > 2) p = i;
    }
  }
  if (f == 65) {
    if (p >= 0)
      s[p] = 66;
    else {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  s[n] = 0;
  puts(s);
  return 0;
}
