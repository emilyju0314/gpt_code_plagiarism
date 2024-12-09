#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
int a[N];
int main() {
  scanf("%d", &n);
  if (n % 4 >= 2) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n / 2; i += 2) {
    a[i] = i + 1, a[i + 1] = n - i + 1;
    a[n - i + 1] = n - i, a[n - i] = i;
  }
  if (n % 4) a[n / 2 + 1] = n / 2 + 1;
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
}
