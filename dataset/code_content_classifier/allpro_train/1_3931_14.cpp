#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int n, k;
long long dp[5][205][2500], F[205], C[15][15], mod = 1000000007;
inline void Add(long long &a, long long v) { a = (a + v) % mod; }
int main() {
  F[0] = 1;
  for (long long i = 1; i < 205; i++) {
    F[i] = (F[i - 1] * i) % mod;
  }
  C[0][0] = 1;
  for (int i = 1; i < 15; i++) {
    for (int j = 0; j <= i; j++) {
      C[i][j] = (C[i - 1][j] + (j ? C[i - 1][j - 1] : 0)) % mod;
    }
  }
  dp[0][0][0] = 1;
  dp[0][0][1] = 1;
  dp[1][0][0] = 1;
  dp[1][0][1] = 2;
  dp[1][0][2] = 1;
  dp[2][0][0] = 1;
  dp[2][0][1] = 3;
  dp[2][0][2] = 1;
  dp[3][0][0] = 1;
  dp[3][0][1] = 5;
  dp[3][0][2] = 5;
  dp[3][0][3] = 1;
  dp[4][0][0] = 1;
  dp[4][0][1] = 8;
  dp[4][0][2] = 16;
  dp[4][0][3] = 8;
  dp[4][0][4] = 1;
  for (int i = 1; i < 205; i++) {
    for (int j = 0; j <= 12 * i + 4; j++) {
      if (j == 1) {
        Add(dp[0][i][j], 1);
      }
      for (int s = 0; s <= min(3, j); s++) {
        Add(dp[0][i][j], C[3][s] * dp[0][i - 1][j - s]);
      }
      if (j == 2) {
        Add(dp[1][i][j], 1);
      }
      if (j >= 1) {
        for (int s = 0; s <= min(3, j - 1); s++) {
          Add(dp[1][i][j], ((2 * C[3][s]) % mod) * dp[0][i - 1][j - 1 - s]);
        }
      }
      for (int s = 0; s <= min(6, j); s++) {
        Add(dp[1][i][j], C[6][s] * dp[1][i - 1][j - s]);
      }
      if (j == 1) {
        Add(dp[2][i][j], 1);
      }
      if (j == 2) {
        Add(dp[2][i][j], 1);
      }
      if (j >= 1) {
        for (int s = 0; s <= min(3, j - 1); s++) {
          Add(dp[2][i][j], ((2 * C[3][s]) % mod) * dp[0][i - 1][j - 1 - s]);
        }
      }
      for (int l = 0; l <= 1; l++) {
        if (j >= l) {
          for (int s = 0; s <= min(6 - 2 * l, j - l); s++) {
            Add(dp[2][i][j], C[6 - 2 * l][s] * dp[2][i - 1][j - l - s]);
          }
        }
      }
      if (j == 2) {
        Add(dp[3][i][j], 2);
      }
      if (j == 3) {
        Add(dp[3][i][j], 1);
      }
      if (j >= 1) {
        for (int s = 0; s <= min(3, j - 1); s++) {
          Add(dp[3][i][j], ((2 * C[3][s]) % mod) * dp[0][i - 1][j - 1 - s]);
        }
      }
      if (j >= 2) {
        for (int s = 0; s <= min(3, j - 2); s++) {
          Add(dp[3][i][j], ((3 * C[3][s]) % mod) * dp[0][i - 1][j - 2 - s]);
        }
      }
      if (j >= 1) {
        for (int s = 0; s <= min(6, j - 1); s++) {
          Add(dp[3][i][j], C[6][s] * dp[1][i - 1][j - 1 - s]);
        }
      }
      for (int l = 0; l <= 1; l++) {
        if (j >= 1 + l) {
          for (int s = 0; s <= min(6 - 2 * l, j - 1 - l); s++) {
            Add(dp[3][i][j],
                ((2 * C[6 - 2 * l][s]) % mod) * dp[2][i - 1][j - 1 - l - s]);
          }
        }
      }
      for (int l = 0; l <= 2; l++) {
        if (j >= l) {
          for (int s = 0; s <= min(9 - 2 * l, j - l); s++) {
            Add(dp[3][i][j],
                ((C[2][l] * C[9 - 2 * l][s]) % mod) * dp[3][i - 1][j - l - s]);
          }
        }
      }
      if (j == 2) {
        Add(dp[4][i][j], 2);
      }
      if (j == 3) {
        Add(dp[4][i][j], 4);
      }
      if (j == 4) {
        Add(dp[4][i][j], 1);
      }
      if (j >= 2) {
        for (int s = 0; s <= min(3, j - 2); s++) {
          Add(dp[4][i][j], ((8 * C[3][s]) % mod) * dp[0][i - 1][j - 2 - s]);
        }
      }
      for (int l = 0; l <= 1; l++) {
        if (j >= l + 1) {
          for (int s = 0; s <= min(6 - 2 * l, j - 1 - l); s++) {
            Add(dp[4][i][j],
                ((4 * C[6 - 2 * l][s]) % mod) * dp[2][i - 1][j - 1 - l - s]);
          }
        }
      }
      if (j >= 3) {
        for (int s = 0; s <= min(3, j - 3); s++) {
          Add(dp[4][i][j], ((4 * C[3][s]) % mod) * dp[0][i - 1][j - 3 - s]);
        }
      }
      if (j >= 2) {
        for (int s = 0; s <= min(6, j - 2); s++) {
          Add(dp[4][i][j], ((2 * C[6][s]) % mod) * dp[1][i - 1][j - 2 - s]);
        }
      }
      for (int l = 0; l <= 1; l++) {
        if (j >= l + 2) {
          for (int s = 0; s <= min(6 - 2 * l, j - 2 - l); s++) {
            Add(dp[4][i][j],
                ((4 * C[6 - 2 * l][s]) % mod) * dp[2][i - 1][j - 2 - l - s]);
          }
        }
      }
      for (int l = 0; l <= 2; l++) {
        if (j >= l + 1) {
          for (int s = 0; s <= min(9 - 2 * l, j - 1 - l); s++) {
            Add(dp[4][i][j], ((C[2][l] * 4 * C[9 - 2 * l][s]) % mod) *
                                 dp[3][i - 1][j - 1 - l - s]);
          }
        }
      }
      for (int l = 0; l <= 4; l++) {
        if (j >= l) {
          for (int s = 0; s <= min(12 - 2 * l, j - l); s++) {
            Add(dp[4][i][j],
                ((C[4][l] * C[12 - 2 * l][s]) % mod) * dp[4][i - 1][j - l - s]);
          }
        }
      }
    }
  }
  while (cin >> n >> k) {
    cout << (dp[4][n][k] * F[k]) % mod << endl;
  }
}
