#include <bits/stdc++.h>
using namespace std;
int mini = 15;
int dn = 0, dc = 0, dtot = 0;
bool is_pres[5][5] = {false};
int hash_back(string s) {
  if (s[0] == 'R')
    return 0;
  else if (s[0] == 'G')
    return 1;
  else if (s[0] == 'B')
    return 2;
  else if (s[0] == 'Y')
    return 3;
  else if (s[0] == 'W')
    return 4;
}
bool nothing(int x, int y, int n, int tickoff[][5]) {
  for (int i = 0; i <= 4; i++)
    if ((is_pres[x][i] && i != y && tickoff[x][i] != 2) ||
        (is_pres[i][y] && i != x && tickoff[i][y] != 2))
      return false;
  return true;
}
bool onlyone(int x, int y, int n, int tickoff[][5]) {
  for (int i = 0; i <= 4; i++)
    if ((1 << x) & n) {
      if (is_pres[x][i] && i != y && tickoff[x][i] == 1) return false;
    } else {
      if (is_pres[i][y] && i != x && tickoff[i][y] == 1) return false;
    }
  return true;
}
void checker() {
  for (int i = 0; i < (1 << 10); ++i) {
    int tickoff[5][5] = {0};
    int tmp = __builtin_popcount(i);
    for (int j = 0; j < 10; ++j)
      if ((1 << j) & i) {
        if (j <= 4) {
          for (int a = 0; a <= 4; a++)
            if (tickoff[j][a] == 0 && is_pres[j][a])
              tickoff[j][a] = 1;
            else if (tickoff[j][a] == 1 && is_pres[j][a])
              tickoff[j][a] = 2;
        } else {
          for (int a = 0; a <= 4; a++)
            if (tickoff[a][j - 5] == 0 && is_pres[a][j - 5])
              tickoff[a][j - 5] = 1;
            else if (tickoff[a][j - 5] == 1 && is_pres[a][j - 5])
              tickoff[a][j - 5] = 2;
        }
      }
    int totknown = 0;
    int zeros = 0;
    for (int x = 0; x <= 4; x++)
      for (int y = 0; y <= 4; y++)
        if (is_pres[x][y]) {
          if (tickoff[x][y] == 2)
            totknown++;
          else if (tickoff[x][y] == 1 && onlyone(x, y, i, tickoff)) {
            totknown++;
            tickoff[x][y] = 2;
          }
          if (tickoff[x][y] == 0) zeros++;
        }
    if (zeros == 1)
      for (int x = 0; x <= 4; x++)
        for (int y = 0; y <= 4; y++)
          if (is_pres[x][y] && tickoff[x][y] == 0 && nothing(x, y, i, tickoff))
            totknown++;
    if (totknown == dtot && tmp < mini) mini = tmp;
  }
}
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  bool colpres[5] = {false};
  bool numpres[5] = {false};
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    int col = hash_back(s);
    int num = s[1] - '1';
    if (!colpres[col]) dc++;
    if (!numpres[num]) dn++;
    if (!is_pres[col][num]) dtot++;
    colpres[col] = true;
    numpres[num] = true;
    is_pres[col][num] = true;
  }
  checker();
  cout << mini << endl;
  return 0;
}
