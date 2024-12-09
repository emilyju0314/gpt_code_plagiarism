#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n;
int a[400005];
int main() {
  int i, j;
  int ans;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  ans = n;
  while (ans - 1 >= 1 && a[ans - 1] == a[ans]) ans--;
  printf("%d", ans - 1);
}
