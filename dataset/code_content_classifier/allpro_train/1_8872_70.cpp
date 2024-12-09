#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main() {
  int n;
  scanf("%d", &(n));
  for (int i = (1); i <= (n); i++) scanf("%d", &(a[i]));
  for (int i = (1); i <= (n); i++) {
    int ans = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] > a[i]) ans++;
    }
    ans++;
    cout << ans << " ";
  }
  return 0;
}
