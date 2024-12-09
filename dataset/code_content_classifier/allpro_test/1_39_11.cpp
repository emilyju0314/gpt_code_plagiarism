#include <bits/stdc++.h>
using namespace std;
int n, a[110], b[110];
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    printf("? ");
    for (int j = 1; j < n; j++) printf("%d ", i + 1);
    puts("1");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (!x) {
      b[n] = i;
      break;
    }
    b[x] = i;
  }
  if (!b[n]) b[n] = n;
  for (int i = 1; i < n; i++)
    if (b[i]) b[i] = b[n] - b[i];
  for (int i = 1; i + b[n] <= n; i++) {
    printf("? ");
    for (int j = 1; j < n; j++) printf("1 ");
    printf("%d\n", i + 1);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    b[x] = b[n] + i;
  }
  printf("! ");
  for (int i = 1; i <= n; i++) printf("%d ", b[i]);
  puts("");
}
