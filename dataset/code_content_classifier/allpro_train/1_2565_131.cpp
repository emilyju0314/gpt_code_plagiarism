#include <bits/stdc++.h>
char board[8][9];
int main() {
  for (int i = 0; i < 8; i++) gets(board[i]);
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    int j;
    for (j = 0; j < 8; j++)
      if (board[i][j] != 'B') break;
    if (j == 8) cnt++;
  }
  if (cnt != 8)
    for (int i = 0; i < 8; i++) {
      int j;
      for (j = 0; j < 8; j++)
        if (board[j][i] != 'B') break;
      if (j == 8) cnt++;
    }
  printf("%d\n", cnt);
  return 0;
}
