#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int even = 0;
  int odd = 0;
  for (int i = 0; i < n; ++i) {
    int sc;
    scanf("%d", &sc);
    if (sc % 2 == 0) {
      ++even;
    } else {
      ++odd;
    }
  }
  int turns = n - k;
  if (turns == 0) {
    if (odd % 2 == 0) {
      printf("Daenerys\n");
      return 0;
    }
    printf("Stannis\n");
    return 0;
  }
  if (turns % 2 == 0) {
    if (k % 2 == 0) {
      printf("Daenerys\n");
      return 0;
    }
    if (even >= (turns / 2 + 1)) {
      printf("Daenerys\n");
      return 0;
    }
    printf("Stannis\n");
    return 0;
  }
  if (turns % 2 == 1) {
    if (k % 2 == 1) {
      if (odd > turns / 2) {
        printf("Stannis\n");
        return 0;
      }
      printf("Daenerys\n");
      return 0;
    }
    if (even > turns / 2 && odd > turns / 2) {
      printf("Stannis\n");
      return 0;
    }
    printf("Daenerys\n");
    return 0;
  }
}
