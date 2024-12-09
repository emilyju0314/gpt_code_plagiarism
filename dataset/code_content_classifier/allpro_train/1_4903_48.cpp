#include <bits/stdc++.h>
using namespace std;
int n, a, use[210000], i, ans;
int main() {
  scanf("%d", &n);
  ans = 1;
  use[0] = 2;
  use[1] = 1;
  scanf("%d", &a);
  for (i = 2; i <= n; i++) {
    scanf("%d", &a);
    if (use[a] == 1) {
      use[a] = 2;
      use[i] = 1;
      continue;
    }
    ans++;
    use[i] = 1;
  }
  printf("%d\n", ans);
}
