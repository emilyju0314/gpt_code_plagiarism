#include <bits/stdc++.h>
using namespace std;
const int maxn = (100000 + 10);
char a[maxn], b[maxn];
int pre[maxn], ens[maxn];
int main() {
  scanf("%s%s", a, b);
  int lena = strlen(a), lenb = strlen(b);
  int p = 0, q = lenb - 1;
  for (int i = 0; i < lena; i++) {
    if (a[i] == b[p]) p++;
    pre[i] = p;
  }
  for (int i = lena - 1; i >= 0; i--) {
    if (a[i] == b[q]) q--;
    ens[i] = q;
  }
  ens[lena] = lenb - 1;
  int ans = 0, maxi = 0;
  for (int i = 0; i < lena; i++) {
    if (pre[i] == 0 && ans < lenb - ens[i] - 1) {
      ans = lenb - ens[i] - 1;
      maxi = i;
    } else if (pre[i] != 0 && pre[i] - 1 < ens[i + 1] + 1 &&
               ans < pre[i] + lenb - ens[i + 1] - 1) {
      ans = pre[i] + lenb - ens[i + 1] - 1;
      maxi = i;
    }
  }
  if (ans == 0)
    printf("-\n");
  else {
    for (int i = 0; i < pre[maxi]; i++) printf("%c", b[i]);
    int i = pre[maxi] == 0 ? maxi : maxi + 1;
    for (i = ens[i] + 1; i < lenb; i++) printf("%c", b[i]);
    printf("\n");
  }
  return 0;
}
