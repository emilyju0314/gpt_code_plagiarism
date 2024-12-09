#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:2560000000000000")
using namespace std;
char mas[10001], out[11000][11101];
int mass[10001] = {};
bool nw[10001] = {};
int n = 0, mx = 0;
int main() {
  gets(mas);
  int tmp = 0;
  while (mas[tmp] != 0) {
    n *= 10;
    n += mas[tmp] - '0';
    tmp++;
  }
  gets(mas);
  int step = 0;
  while (step < n) {
    int sk = 1;
    nw[step] = true;
    while (true) {
      if (mas[step] == '[') {
        sk += 2;
        mass[step] = sk;
        mx = max(mx, sk);
        step++;
      } else if (mas[step] == ']') {
        mass[step] = sk;
        mx = max(mx, sk);
        sk -= 2;
        step++;
        if (sk == 1) break;
      } else {
        goto st;
        step++;
      }
    }
  }
st:
  for (int i(0); i < n; i++) {
    mass[i] = mx - mass[i] + 3;
  }
  int k = 0;
  for (int i(0); i < n; i = i) {
    if (i < n - 1) {
      if (mas[i] == '[' && mas[i + 1] == ']') {
        for (int j((mx - mass[i]) / 2); j <= mass[i] / 2 + mx / 2; j++) {
          out[k][j] = '|';
          out[k + 4][j] = '|';
        }
        out[k + 1][(mx - mass[i]) / 2] = '-';
        out[k + 1][mass[i] / 2 + mx / 2] = '-';
        out[k + 3][(mx - mass[i]) / 2] = '-';
        out[k + 3][mass[i] / 2 + mx / 2] = '-';
        out[k][(mx - mass[i]) / 2] = '+';
        out[k][mass[i] / 2 + mx / 2] = '+';
        out[k + 4][(mx - mass[i]) / 2] = '+';
        out[k + 4][mass[i] / 2 + mx / 2] = '+';
        k += 5;
        i += 2;
      } else {
        if (mas[i] == '[') {
          for (int j((mx - mass[i]) / 2); j <= mass[i] / 2 + mx / 2; j++) {
            out[k][j] = '|';
          }
          out[k + 1][(mx - mass[i]) / 2] = '-';
          out[k + 1][mass[i] / 2 + mx / 2] = '-';
          out[k][(mx - mass[i]) / 2] = '+';
          out[k][mass[i] / 2 + mx / 2] = '+';
          k += 1;
          i++;
        } else if (mas[i] == ']') {
          for (int j((mx - mass[i]) / 2); j <= mass[i] / 2 + mx / 2; j++) {
            out[k][j] = '|';
          }
          out[k - 1][(mx - mass[i]) / 2] = '-';
          out[k - 1][mass[i] / 2 + mx / 2] = '-';
          out[k][(mx - mass[i]) / 2] = '+';
          out[k][mass[i] / 2 + mx / 2] = '+';
          k += 1;
          i++;
        }
      }
    } else {
      if (mas[i] == '[') {
        for (int j((mx - mass[i]) / 2); j <= mass[i] / 2 + mx / 2; j++) {
          out[k][j] = '|';
        }
        out[k + 1][(mx - mass[i]) / 2] = '-';
        out[k + 1][mass[i] / 2 + mx / 2] = '-';
        out[k][(mx - mass[i]) / 2] = '+';
        out[k][mass[i] / 2 + mx / 2] = '+';
        k += 1;
        i++;
      } else if (mas[i] == ']') {
        for (int j((mx - mass[i]) / 2); j <= mass[i] / 2 + mx / 2; j++) {
          out[k][j] = '|';
        }
        out[k - 1][(mx - mass[i]) / 2] = '-';
        out[k - 1][mass[i] / 2 + mx / 2] = '-';
        out[k][(mx - mass[i]) / 2] = '+';
        out[k][mass[i] / 2 + mx / 2] = '+';
        k += 1;
        i++;
      }
    }
  }
  for (int i(0); i < mx; i++) {
    for (int j(0); j < k; j++) {
      mas[j] = out[j][i];
      if (mas[j] != '-' && mas[j] != '+' && mas[j] != '|') mas[j] = ' ';
    }
    mas[k] = 0;
    puts(mas);
  }
  return 0;
}
