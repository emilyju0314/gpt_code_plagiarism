#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", n / 2);
    if (n == 3)
      printf("3");
    else
      printf("2");
    for (int i = 2; i < n / 2; i++) printf(" 2");
    if (n % 2 == 0 && n != 2)
      printf(" 2");
    else if (n != 2 && n != 3)
      printf(" 3");
    printf("\n");
  }
}
