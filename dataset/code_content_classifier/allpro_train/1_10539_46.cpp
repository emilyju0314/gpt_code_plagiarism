#include <bits/stdc++.h>
using namespace std;
void crash() {
  int ll = 0;
  cout << 1 / ll;
}
const int INF = 1 << 30;
const int MAXN = 3010;
int D[MAXN][MAXN];
int N, K;
char S[300][300];
int C[300][300];
void Read() {
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    scanf("%s", S[i] + 1);
  }
}
void CheckH(int i, int j) {
  for (int k = 0; k < K; ++k) {
    if (S[i + k][j] != '.') {
      return;
    }
  }
  for (int k = 0; k < K; ++k) {
    C[i + k][j]++;
  }
}
void CheckV(int i, int j) {
  for (int k = 0; k < K; ++k) {
    if (S[i][j + k] != '.') {
      return;
    }
  }
  for (int k = 0; k < K; ++k) {
    C[i][j + k]++;
  }
}
void Solve() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      CheckH(i, j);
      CheckV(i, j);
    }
  }
  int ix = 1, jx = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (C[i][j] > C[ix][jx]) {
        ix = i;
        jx = j;
      }
    }
  }
  cout << ix << " " << jx << endl;
}
int main() {
  Read();
  Solve();
  return 0;
}
