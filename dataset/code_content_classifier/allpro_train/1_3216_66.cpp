#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a[3];
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    sort(a, a + 3);
    if (a[0] + a[1] <= a[2])
      printf("%d\n", a[0] + a[1]);
    else
      printf("%d\n", (a[0] + a[1] + a[2]) / 2);
  }
  return 0;
}
