#include <bits/stdc++.h>
int main() {
  int i, x = 0, y = 0, z = 0, k = 0, l = 0, d = 0;
  int A[6];
  for (i = 0; i < 6; i++) {
    scanf("%d", &A[i]);
  }
  for (i = 0; i < 6; i++) {
    if (A[i] == A[0]) {
      x++;
    }
  }
  for (i = 0; i < 6; i++) {
    if (A[i] == A[1]) {
      y++;
    }
  }
  for (i = 0; i < 6; i++) {
    if (A[i] == A[2]) {
      z++;
    }
  }
  if (x >= 4) {
    for (i = 0; i < 6; i++) {
      if (A[i] != A[0] && d == 1) {
        l = A[i];
      }
      if (A[i] != A[0] && d == 0) {
        k = A[i];
        d = 1;
      }
    }
    if (k == 0) {
      k = A[0];
    }
    if (l == 0) {
      l = A[0];
    }
    if (k == l) {
      printf("Elephant\n");
    } else {
      printf("Bear\n");
    }
  } else if (y >= 4) {
    for (i = 0; i < 6; i++) {
      if (A[i] != A[1] && d == 1) {
        l = A[i];
      }
      if (A[i] != A[1] && d == 0) {
        k = A[i];
        d = 1;
      }
    }
    if (k == 0) {
      k = A[1];
    }
    if (l == 0) {
      l = A[1];
    }
    if (k == l) {
      printf("Elephant\n");
    } else {
      printf("Bear\n");
    }
  } else if (z >= 4) {
    for (i = 0; i < 6; i++) {
      if (A[i] != A[2] && d == 1) {
        l = A[i];
      }
      if (A[i] != A[2] && d == 0) {
        k = A[i];
        d = 1;
      }
    }
    if (k == 0) {
      k = A[2];
    }
    if (l == 0) {
      l = A[2];
    }
    if (k == l) {
      printf("Elephant\n");
    } else {
      printf("Bear\n");
    }
  } else {
    printf("Alien\n");
  }
  return 0;
}
