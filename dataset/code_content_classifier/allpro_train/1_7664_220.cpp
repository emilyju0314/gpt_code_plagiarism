#include <bits/stdc++.h>
using namespace std;
const int N = 300;
int X[3], Y[3], P[3];
bool line(int x1, int y1, int x2, int y2, int x3, int y3) {
  if (x1 < y1) {
    int l = y1;
    if (y1 == l && y2 == l && y3 == l && x1 + x2 + x3 == l) {
      printf("%d\n", l);
      for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
          if (j < x1)
            printf("%c", (char)(P[0] + 'A'));
          else if (j < x1 + x2)
            printf("%c", (char)(P[1] + 'A'));
          else
            printf("%c", (char)(P[2] + 'A'));
        }
        puts("");
      }
      return true;
    }
  } else {
    int l = x1;
    if (x1 == l && x2 == l && x3 == l && y1 + y2 + y3 == l) {
      printf("%d\n", l);
      for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
          if (i < y1)
            printf("%c", (char)(P[0] + 'A'));
          else if (i < y1 + y2)
            printf("%c", (char)(P[1] + 'A'));
          else
            printf("%c", (char)(P[2] + 'A'));
        }
        puts("");
      }
      return true;
    }
  }
  return false;
}
bool nonline(int x1, int y1, int x2, int y2, int x3, int y3) {
  int l = x1 + x2;
  if (y1 == y2 && x3 == l && y1 + y3 == l) {
    printf("%d\n", l);
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++) {
        if (i < y1)
          printf("%c", (char)(P[j < x1 ? 0 : 1] + 'A'));
        else
          printf("%c", (char)(P[2] + 'A'));
      }
      puts("");
    }
    return true;
  }
  l = x1 + x3;
  if (x1 == x2 && y1 + y2 == l && y3 == l) {
    printf("%d\n", l);
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++) {
        if (j < x1)
          printf("%c", (char)(P[i < y1 ? 0 : 1] + 'A'));
        else
          printf("%c", (char)(P[2] + 'A'));
      }
      puts("");
    }
    return true;
  }
  return false;
}
bool solve(int testNumber) {
  for (int i = 0; i < 3; i++) {
    if (scanf("%d %d", &X[i], &Y[i]) == EOF) return false;
    P[i] = i;
  }
  do {
    for (int i = 0; i < 8; i++) {
      int x1, y1, x2, y2, x3, y3;
      if ((i & 4) > 0) {
        x1 = Y[P[0]];
        y1 = X[P[0]];
      } else {
        x1 = X[P[0]];
        y1 = Y[P[0]];
      }
      if ((i & 2) > 0) {
        x2 = Y[P[1]];
        y2 = X[P[1]];
      } else {
        x2 = X[P[1]];
        y2 = Y[P[1]];
      }
      if ((i & 1) > 0) {
        x3 = Y[P[2]];
        y3 = X[P[2]];
      } else {
        x3 = X[P[2]];
        y3 = Y[P[2]];
      }
      if (line(x1, y1, x2, y2, x3, y3) || nonline(x1, y1, x2, y2, x3, y3))
        return true;
    }
  } while (next_permutation(P, P + 3));
  puts("-1");
  return true;
}
int main() {
  for (int i = 1; solve(i); i++)
    ;
  return 0;
}
