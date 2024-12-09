#include <bits/stdc++.h>
using namespace std;
int n, num[200010], ins = -1, des = 123456789, res[200010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  for (int i = 1; i <= n; i++) {
    if (num[i] > ins && (num[i] >= des || num[i] < num[i + 1]))
      ins = num[i], res[i] = 0;
    else if (des > num[i])
      des = num[i], res[i] = 1;
    else
      return 0 * puts("NO");
  }
  printf("YES\n%d", res[1]);
  for (int i = 2; i <= n; i++) printf(" %d", res[i]);
  return 0;
}
