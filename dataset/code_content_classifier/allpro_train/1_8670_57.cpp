#include <bits/stdc++.h>
using namespace std;
char board[2048][2048];
int rows[2][2048];
int cols[2][2048];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) scanf(" %c", &board[i][j]);
  int ans = 0;
  for (int x = 0; x < 2; x++) {
    for (int i = 0; i < N - 1; i++)
      for (int j = N - 1; j > i; j--) {
        int d = rows[x][i] ^ cols[x][j];
        if (!d != (board[i][j] == '0')) {
          ans++;
          rows[x][i] ^= 1;
          cols[x][j] ^= 1;
        }
        board[i][j] = board[j][i];
      }
  }
  for (int i = 0; i < N; i++)
    if (!(rows[0][i] ^ rows[1][i] ^ cols[0][i] ^ cols[1][i]) !=
        (board[i][i] == '0'))
      ans++;
  printf("%d\n", ans);
  return 0;
}
