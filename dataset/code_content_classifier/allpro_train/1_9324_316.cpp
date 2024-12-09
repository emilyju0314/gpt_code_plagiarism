#include <bits/stdc++.h>
using namespace std;
unsigned int a[301000], n, i, temp, stat, j;
unsigned int newstat() {
  for (j = stat - 1; j > 0; j--)
    if (a[j] == 0) return j;
}
int main() {
  scanf("%u", &n);
  ;
  printf("1 ");
  stat = n;
  for (i = 1; i < n; i++) {
    scanf("%u", &temp);
    ;
    if (temp == stat)
      stat = newstat();
    else
      a[temp] = 1;
    printf("%u ", i - (n - stat) + 1);
    ;
  }
  printf("1\n");
  return 0;
}
