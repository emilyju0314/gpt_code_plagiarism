#include <bits/stdc++.h>
using namespace std;
const int NMax = 51000;
int N;
char A[NMax];
int main() {
  scanf("%s", A);
  N = strlen(A);
  int len = 1;
  while (len <= N / 2) {
    int cnt = 0, start = len;
    for (int i = len; i < N; i++) {
      if (cnt == len) break;
      if (A[i] != A[i - len]) {
        start = i + 1;
        cnt = 0;
      } else
        cnt++;
    }
    if (cnt == len) {
      for (int i = start + len; i < N; i++) A[i - len] = A[i];
      N -= len;
      A[N] = '\0';
    } else
      len++;
  }
  printf("%s", A);
  getchar();
  getchar();
  return 0;
}
