#include <bits/stdc++.h>
using namespace std;
int a, b, x;
int main(void) {
  scanf("%d %d %d", &a, &b, &x);
  if (x % 2 == 0) {
    if (a > b) {
      for (int i = 1; i <= x / 2; i++) printf("01");
      for (int i = 1; i <= (b - x / 2); i++) printf("1");
      for (int i = 1; i <= (a - x / 2); i++) printf("0");
    } else {
      for (int i = 1; i <= x / 2; i++) printf("10");
      for (int i = 1; i <= (a - x / 2); i++) printf("0");
      for (int i = 1; i <= (b - x / 2); i++) printf("1");
    }
  } else {
    if (a > b) {
      for (int i = 1; i <= x / 2; i++) printf("01");
      for (int i = 1; i <= (a - x / 2); i++) printf("0");
      for (int i = 1; i <= (b - x / 2); i++) printf("1");
    } else {
      for (int i = 1; i <= x / 2; i++) printf("10");
      for (int i = 1; i <= (b - x / 2); i++) printf("1");
      for (int i = 1; i <= (a - x / 2); i++) printf("0");
    }
  }
  printf("\n");
  return false;
}
