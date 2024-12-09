#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:400000000")
int n, m;
char c[101][10010];
int dx[] = {1, -1};
int main() {
  cin >> n >> m;
  gets(c[0]);
  for (int i = 0; i < (n); i++) {
    gets(c[i] + 1);
    c[i][0] = '#';
    c[i][m + 1] = '#';
  }
  for (int i = 0; i < (m + 2); i++) c[n][i] = '#';
  int y = 0, x = 1, d = 0;
  long long time = 0;
  while (1) {
    if (y == n - 1) {
      cout << time;
      return 0;
    }
    int preL = -1, preR = -1;
    int sameL = 0, sameR = 0;
    while (1) {
      if (d == 0) {
        if (preR != -1) {
          time += preR - x;
          x = preR;
        }
      }
      if (d == 1) {
        if (preL != -1) {
          time += x - preL;
          x = preL;
        }
      }
      while (1) {
        if (c[y + 1][x] == '.') break;
        if (c[y][x + dx[d]] == '.')
          x += dx[d], time++;
        else
          break;
      }
      if (c[y + 1][x] == '.') {
        y++;
        time++;
        break;
      }
      if (d == 0) {
        if (preR == x) sameR = 1;
        preR = x;
      } else {
        if (preL == x) sameL = 1;
        preL = x;
      }
      if (sameR && sameL) {
        cout << "Never";
        return 0;
      }
      if (c[y][x + dx[d]] == '#') {
        d ^= 1;
        time++;
      }
      if (c[y][x + dx[d]] == '+') {
        time++;
        c[y][x + dx[d]] = '.';
        d ^= 1;
      }
    }
  }
}
