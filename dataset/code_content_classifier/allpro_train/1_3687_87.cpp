#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  int a[20] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
               31, 37, 41, 43, 47, 49, 25, 9,  4,  53};
  char s[5];
  n = 2;
  printf("%d\n", n);
  fflush(stdout);
  scanf("%s", s);
  if (s[0] == 'y') {
    for (i = 1; i <= 19; i++) {
      printf("%d\n", a[i]);
      fflush(stdout);
      scanf("%s", s);
      if (s[0] == 'y') {
        printf("composite");
        return 0;
      }
    }
  } else {
    int count = 0;
    for (i = 1; i <= 19; i++) {
      printf("%d\n", a[i]);
      fflush(stdout);
      scanf("%s", s);
      if (s[0] == 'y') count++;
      if (count > 1) {
        printf("composite");
        return 0;
      }
    }
  }
  printf("prime");
  fflush(stdout);
}
