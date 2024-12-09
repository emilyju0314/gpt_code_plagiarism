#include <bits/stdc++.h>
using namespace std;
char board[8][8];
int main() {
  int i, j;
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++) cin >> board[i][j];
  int minn = 8, minnb = 8;
  for (j = 0; j < 8; j++) {
    for (i = 0; i < 8; i++) {
      if (board[i][j] == 'B')
        break;
      else if (board[i][j] == 'W') {
        minn = minn < i ? minn : i;
        break;
      }
    }
  }
  for (j = 0; j < 8; j++)
    for (i = 7; i >= 0; i--) {
      if (board[i][j] == 'W')
        break;
      else if (board[i][j] == 'B') {
        minnb = minnb > (7 - i) ? 7 - i : minnb;
        break;
      }
    }
  if (minn <= minnb)
    cout << "A";
  else
    cout << "B";
  return 0;
}
