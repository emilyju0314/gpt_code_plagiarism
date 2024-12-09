#include <bits/stdc++.h>
using namespace std;
long long n, sx, sy, dx, dy, t;
vector<vector<long long> > multiply(vector<vector<long long> > A,
                                    vector<vector<long long> > B) {
  vector<vector<long long> > C;
  C.resize(7);
  for (int i = 1; i <= 6; i++) {
    C[i].resize(7);
  }
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 6; j++) {
      C[i][j] = 0;
      for (int k = 1; k <= 6; k++) {
        C[i][j] += A[i][k] * B[k][j];
        C[i][j] = (C[i][j] % n + n) % n;
      }
    }
  }
  return C;
}
vector<vector<long long> > Pow(vector<vector<long long> > A, long long P) {
  if (P == 1) return A;
  if (P & 1) return multiply(Pow(A, P - 1), A);
  vector<vector<long long> > Res = Pow(A, P / 2);
  return multiply(Res, Res);
}
void calc(long long N) {
  if (N == 0) return;
  std::vector<long long> F(7);
  F[1] = sx - 1;
  F[2] = sy - 1;
  F[3] = dx;
  F[4] = dy;
  F[5] = 1;
  F[6] = 1;
  vector<vector<long long> > Res;
  Res.resize(7);
  for (int i = 1; i <= 6; i++) Res[i].resize(7);
  Res[1][1] = 2, Res[1][2] = 1, Res[1][3] = 1, Res[1][4] = 0, Res[1][5] = 1,
  Res[1][6] = 1;
  Res[2][1] = 1, Res[2][2] = 2, Res[2][3] = 0, Res[2][4] = 1, Res[2][5] = 1,
  Res[2][6] = 1;
  Res[3][1] = 1, Res[3][2] = 1, Res[3][3] = 1, Res[3][4] = 0, Res[3][5] = 1,
  Res[3][6] = 1;
  Res[4][1] = 1, Res[4][2] = 1, Res[4][3] = 0, Res[4][4] = 1, Res[4][5] = 1,
  Res[4][6] = 1;
  Res[5][5] = 1, Res[5][6] = 1;
  Res[6][6] = 1;
  Res = Pow(Res, N);
  sx = 0, sy = 0;
  for (int i = 1; i <= 6; i++) {
    sx = (sx + Res[1][i] * F[i]);
    sx = (sx % n + n) % n;
  }
  for (int i = 1; i <= 6; i++) {
    sy = (sy + Res[2][i] * F[i]);
    sy = (sy % n + n) % n;
  }
  sx += 1, sy += 1;
}
int main() {
  cin >> n >> sx >> sy >> dx >> dy >> t;
  calc(t);
  cout << sx << " " << sy << endl;
  return 0;
}
