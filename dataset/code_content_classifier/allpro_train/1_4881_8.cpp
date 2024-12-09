#include <bits/stdc++.h>
using namespace std;
const int NMax = 110;
char A[NMax][NMax];
int N, M;
int main() {
  scanf("%d%d", &N, &M);
  if (N == 5) {
    printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
    return 0;
  }
  if (N == 3) {
    printf(">vv\n^<.\n^.<\n1 3\n");
    return 0;
  }
  for (int i = 100; i >= 2; i -= 2) {
    int a = i - 2, b = i - 1;
    A[0][b] = '<';
    A[99][a] = '>';
    for (int j = 0; j < 49; j++) A[j][a] = 'v', A[99 - j][b] = '^';
    for (int j = 49; j < 99; j += 2)
      A[j][a] = '.', A[j + 1][a] = 'v', A[99 - j][b] = '.',
      A[99 - j - 1][b] = '^';
  }
  for (int i = 0; i < 100; i++) printf("%s\n", A[i]);
  printf("1 100\n");
  return 0;
}
