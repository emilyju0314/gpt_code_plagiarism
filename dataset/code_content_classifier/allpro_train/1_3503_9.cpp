#include <bits/stdc++.h>
using namespace std;
int res[4];
int main() {
  int n;
  int a[4];
  int flag = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  if (n == 1) {
    a[1] = a[0];
    a[2] = a[3] = 3 * a[0];
    puts("YES");
    for (int i = 1; i < 4; i++) printf("%d\n", a[i]);
  } else if (n == 2) {
    sort(a, a + n);
    if (a[1] > 3 * a[0])
      puts("NO");
    else {
      a[3] = 3 * a[0];
      a[2] = 4 * a[0] - a[1];
      printf("YES\n%d\n%d\n", a[2], a[3]);
    }
  } else if (n == 3) {
    sort(a, a + n);
    if (a[2] > a[0] * 3) {
      flag = 1;
      puts("NO");
    } else if (a[2] == a[0] * 3) {
      printf("YES\n%d\n", a[0] * 4 - a[1]);
    } else {
      a[3] = 3 * a[0];
      if (a[0] * 4 != a[1] + a[2]) {
        if (a[2] % 3 != 0)
          puts("NO");
        else {
          a[3] = a[2] / 3;
          if (a[3] * 4 != a[0] + a[1])
            puts("NO");
          else
            printf("YES\n%d\n", a[3]);
        }
      } else
        printf("YES\n%d\n", a[3]);
    }
  } else if (n == 4) {
    sort(a, a + 4);
    if (!(a[0] * 3 == a[3] && a[0] + a[3] == a[1] + a[2]))
      puts("NO");
    else {
      puts("YES");
    }
  } else
    printf("YES\n1\n1\n3\n3\n");
}
