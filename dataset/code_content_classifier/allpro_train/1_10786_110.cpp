#include <bits/stdc++.h>
using namespace std;
int a[200] = {0}, b[200] = {0};
char s[10];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int i, j, k = 0, h = 0;
  for (i = 2; i <= 100; i++) {
    if (a[i] == 1) continue;
    b[h++] = i;
    for (j = i * 2; j <= 100; j += i) a[j] = 1;
  }
  for (i = 0; i < 4; i++) {
    printf("%d\n", b[i]);
    fflush(stdout);
    scanf(" %s", s);
    if (s[0] == 'y') break;
  }
  if (i == 4) {
    printf("prime\n");
    fflush(stdout);
    return 0;
  }
  printf("%d\n", b[i] * b[i]);
  fflush(stdout);
  scanf(" %s", s);
  if (s[0] == 'y') {
    printf("composite\n");
    fflush(stdout);
    return 0;
  }
  for (j = i + 1; j < 15; j++) {
    printf("%d\n", b[j]);
    fflush(stdout);
    scanf(" %s", s);
    if (s[0] == 'y') break;
  }
  if (j < 15 && b[j] * b[i] <= 100) {
    printf("composite\n");
    fflush(stdout);
  } else {
    printf("prime\n");
    fflush(stdout);
  }
  return 0;
}
