#include <bits/stdc++.h>
using namespace std;
char s[1000010], c[1000010];
int r, l;
int main() {
  scanf("%s %s", &s, &c);
  for (r = 0; s[r] == c[r];) r++;
  for (l = strlen(c); l >= 0 && c[l] == s[l + 1];) l--;
  if (r > l)
    printf("%d\n", r - l);
  else
    printf("0");
  for (int i = l + 1; i <= r; i++) printf("%d ", i + 1);
  return 0;
}
