#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[300000], k[300000], tmp[300000];
bool ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int s = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &k[i]);
    s += k[i];
  }
  for (int i = 1; i <= s; i++) {
    tmp[a[i]]++;
  }
  int j = 1;
  while (j <= m && tmp[j] == k[j]) j++;
  if (j == m + 1)
    ans = 1;
  else {
    for (int i = 2; i + s - 1 <= n; i++) {
      tmp[a[i - 1]]--;
      tmp[a[i + s - 1]]++;
      j = 1;
      while (j <= m && tmp[j] == k[j]) j++;
      if (j == m + 1) {
        ans = 1;
        break;
      }
    }
  }
  if (ans)
    puts("YES");
  else
    puts("NO");
  return 0;
}
