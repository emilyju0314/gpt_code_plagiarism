#include <bits/stdc++.h>
using namespace std;
const int SZ = 200010;
int a[SZ], b[SZ], mp[SZ];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mp[a[i]] = i;
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  int i = 1, j = 1, pos = n, flag = 0;
  while (i <= n && j <= n) {
    if (a[i] == b[j])
      i++, j++;
    else {
      flag = 1;
      int x = b[j];
      pos = min(pos, mp[x]);
      j++;
    }
  }
  if (!flag)
    puts("0");
  else
    printf("%d", n - pos + 1);
  return 0;
}
