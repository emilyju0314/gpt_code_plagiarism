#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int a[2 * N];
int main() {
  int n;
  scanf("%d", &n);
  if (n % 2 == 0) {
    printf("NO");
    return 0;
  }
  a[0] = 1;
  int nxt = 2;
  bool nn = true;
  for (int i = 1; i <= n; i++) {
    if (nn) {
      a[i + n - 1] = nxt++;
      if (i < n) a[i + n] = nxt++;
      nn = false;
    } else {
      a[i - 1] = nxt++;
      if (i < n) a[i] = nxt++;
      ;
      nn = true;
    }
  }
  printf("YES\n");
  for (int i = 0; i < 2 * n; i++) {
    printf("%d ", a[i]);
  }
  getchar();
  getchar();
}
