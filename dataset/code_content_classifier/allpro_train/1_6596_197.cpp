#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const double EPS = 1e-10;
inline double SQR(double x) { return x * x; }
inline long long SQR(long long x) { return x * x; }
inline int SQR(int x) { return x * x; }
inline double SQR3(double x) { return x * x * x; }
inline void DEBUG() { puts("jackie"); }
inline bool zero(double x) { return abs(x) < EPS; }
inline int inInt() {
  int x = 0, c;
  while ((unsigned int)((c = getchar()) - '0') >= 10) {
    if ('-' == c) return -inInt();
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while ((unsigned int)((c = getchar()) - '0') < 10);
  return x;
}
inline void outInt(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) outInt(x / 10);
  putchar((x % 10) + '0');
}
char mat[10][10];
char tmp[10][10];
int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
inline bool isOK(int x, int y) { return (x >= 0 && x < 8 && y >= 0 && y < 8); }
bool isWon() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ('A' == mat[i][j]) return false;
    }
  }
  return true;
}
bool isLose() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ('M' == mat[i][j]) return false;
    }
  }
  return true;
}
int main() {
  for (int i = 0; i < 8; i++) {
    gets(mat[i]);
  }
  while (true) {
    memcpy(tmp, mat, sizeof(mat));
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if ('M' == mat[i][j]) {
          int x, y;
          for (int k = 0; k < 8; k++) {
            x = i + dir[k][0], y = j + dir[k][1];
            if (isOK(x, y) && 'S' != mat[x][y]) {
              tmp[x][y] = 'M';
            }
          }
        }
      }
    }
    memcpy(mat, tmp, sizeof(tmp));
    if (isWon()) {
      puts("WIN");
      return 0;
    }
    for (int i = 7; i >= 0; i--) {
      for (int j = 0; j < 8; j++) {
        if ('S' == mat[i][j]) {
          tmp[i][j] = '.';
          if (isOK(i + 1, j)) tmp[i + 1][j] = 'S';
        }
      }
    }
    memcpy(mat, tmp, sizeof(tmp));
    if (isLose()) {
      puts("LOSE");
      return 0;
    }
  }
  return 0;
}
