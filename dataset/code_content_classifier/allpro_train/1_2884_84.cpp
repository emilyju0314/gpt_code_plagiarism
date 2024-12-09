#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int A[1009][1009];
int S1[1009][1009];
int S2[1009][1009];
void read(int &x) {
  x = 0;
  char ch = getchar();
  for (; ch == '\n' || ch == ' ' || ch == '\r'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 3) + (x << 1) + ch - '0';
  return;
}
int main() {
  cin >> N >> M >> K;
  for (register int i = 1; i <= N; i++)
    for (register int j = 1; j <= M; j++) read(A[i][j]);
  for (register int j = 1; j <= M; j++)
    for (register int i = 1; i <= N; i++) {
      S1[i][j] = S1[i - 1][j - 1] + A[i][j];
      S2[i][j] = S2[i + 1][j - 1] + A[i][j];
    }
  long long Ans = -1;
  int XX, YY;
  for (register int i = K; i <= N - K + 1; i++)
    for (register int j = K; j <= M - K + 1; j++) {
      long long Cnt = (long long)A[i][j] * K;
      for (register int p = 1; p < K; p++) {
        long long Add = 0;
        Add += S1[i][j + p] - S1[i - p][j];
        Add += S1[i + p][j] - S1[i][j - p];
        Add -= A[i][j + p];
        Add += A[i][j - p];
        Add += S2[i - p][j] - S2[i][j - p];
        Add += S2[i][j + p] - S2[i + p][j];
        Cnt += Add * (K - p);
      }
      if (Cnt > Ans) {
        Ans = Cnt;
        XX = i, YY = j;
      }
      if (clock() >= CLOCKS_PER_SEC * 0.3) {
        cout << XX << ' ' << YY << endl;
        return 0;
      }
    }
  cout << XX << ' ' << YY << endl;
  return 0;
}
