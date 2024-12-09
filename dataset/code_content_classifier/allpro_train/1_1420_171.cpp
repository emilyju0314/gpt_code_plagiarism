#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int temp = a;
  if (a > b) temp = b;
  printf("%d\n", temp + 1);
  int i = a, j = 0;
  while (i > -1 && j <= b) {
    printf("%d %d\n", i, j);
    i--;
    j++;
  }
  return 0;
}
