#include <bits/stdc++.h>
using namespace std;
char a[1000005], b[1000005];
int c[1000005];
int main() {
  int i, ret = 0, ans = 0;
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  int lena = 0, lenb = 0;
  for (i = 1; b[i]; ++i) {
    if (b[i] == '1') ret++;
    lenb++;
  }
  for (i = 1; a[i] != '\0'; ++i) {
    lena++;
    c[i] = c[i - 1];
    if (a[i] == '1') c[i]++;
  }
  if (ret % 2 == 0) {
    for (i = 1; i <= lena - lenb + 1; ++i) {
      if ((c[i + lenb - 1] - c[i - 1]) % 2 == 0) ans++;
    }
  } else {
    for (i = 1; i <= lena - lenb + 1; ++i) {
      if ((c[i + lenb - 1] - c[i - 1]) % 2 == 1) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
