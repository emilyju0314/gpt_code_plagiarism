#include <bits/stdc++.h>
using namespace std;
string s1, s2, A, B, C;
int len_A, len_B, len_C;
int *b;
void preprocess() {
  int i = 0, j = -1;
  b[0] = -1;
  while (i < len_B) {
    while (j >= 0 && B[i] != B[j]) j = b[j];
    i++;
    j++;
    b[i] = j;
  }
}
int *b2;
void preprocess2() {
  int i = 0, j = -1;
  b2[0] = -1;
  while (i < len_C) {
    while (j >= 0 && C[i] != C[j]) j = b2[j];
    i++;
    j++;
    b2[i] = j;
  }
}
int *z;
void Z() {
  int L = 0, R = 0, i, k;
  for (i = 1; i < len_A; ++i) {
    if (i > R) {
      L = R = i;
      while (R < len_A && A[R - L] == A[R]) R++;
      z[i] = R - L;
      R--;
    } else {
      k = i - L;
      if (z[k] < R - i + 1)
        z[i] = z[k];
      else {
        L = i;
        while (R < len_A && A[R - L] == A[R]) R++;
        z[i] = R - L;
        R--;
      }
    }
  }
}
int main() {
  getline(cin, s1);
  getline(cin, s2);
  if (s1.length() != s2.length()) {
    puts("-1 -1");
    return 0;
  }
  B = s1;
  reverse(B.begin(), B.end());
  B += '\0' + s2;
  len_B = B.length();
  b = new int[len_B + 1];
  preprocess();
  A = s2 + '\0' + s1;
  len_A = A.length();
  z = new int[len_A + 1];
  Z();
  C = s2;
  reverse(C.begin(), C.end());
  C = s1 + '\0' + C;
  len_C = C.length();
  b2 = new int[len_C + 1];
  preprocess2();
  int i, len = s1.length(), ini = -1, fin = -1;
  for (i = 0; i < len; ++i) {
    len_B = b[len + i + 1];
    if (z[len + 1 + len - (i - len_B) - b[len + i + 1]] == i - len_B ||
        (len - z[len + 1 + len - (i - len_B) - b[len + i + 1]] ==
         b2[len_C - i])) {
      if (b2[len_C - i] == len - (i - len_B) - b[len + i + 1]) {
        ini = len - (i - len_B + 1) - b[len + i + 1];
        fin = ini + i - len_B + 1;
        break;
      }
    }
  }
  if (fin == len) {
    ini--;
    fin--;
  }
  if (ini == -1) fin = -1;
  printf("%d %d\n", ini, fin);
  return 0;
}
