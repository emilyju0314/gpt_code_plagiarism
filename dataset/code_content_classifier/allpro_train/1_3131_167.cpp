#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    if (n % 2 == 0) {
      for (int i = n / 2; i >= 1; i--) printf("%d %d ", a[i], a[n + 1 - i]);
    } else {
      printf("%d ", a[(n + 1) / 2]);
      for (int i = n / 2; i >= 1; i--) printf("%d %d ", a[i], a[n + 1 - i]);
    }
    printf("\n");
  }
  return 0;
}
