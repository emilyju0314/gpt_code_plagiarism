#include <bits/stdc++.h>
using namespace std;
int A[1 << 20];
long long R[2][256][2];
long long S[256][2];
int main() {
  int n;
  scanf("%d", &n);
  int i, j, k;
  for (i = (0); i < (n); ++i) scanf("%d", &A[i]);
  memset(R, 0, sizeof(R));
  memset(S, 0, sizeof(S));
  R[0][0][0] = 1;
  for (i = (0); i < (n); ++i) {
    int prev = i & 1;
    int next = prev ^ 1;
    memset(S, 0, sizeof(S));
    for (j = (0); j < (201); ++j)
      for (k = (0); k < (2); ++k)
        S[j + 1][k] = (S[j][k] + R[prev][j][k]) % 998244353;
    memset(R[next], 0, sizeof(R[next]));
    for (j = (1); j < (201); ++j)
      if (A[i] == -1 || A[i] == j) {
        R[next][j][0] += S[201][0] - S[j + 1][0] + 998244353;
        R[next][j][0] += R[prev][j][0] + R[prev][j][1];
        R[next][j][1] += S[j][0] + S[j][1];
        R[next][j][0] %= 998244353;
        R[next][j][1] %= 998244353;
      }
  }
  long long res = 0;
  for (i = (1); i < (201); ++i) res += R[n & 1][i][0];
  printf("%lld\n", res % 998244353);
  return 0;
};
