#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int a[N];
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    if (a[i] == 1)
      ans++;
    else if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1)
      ans++;
  printf("%d\n", ans);
  return 0;
}
