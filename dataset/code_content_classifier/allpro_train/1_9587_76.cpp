#include <bits/stdc++.h>
using namespace std;
int cube[6][4];
int copyCube[6][4];
bool check() {
  int fullSides = 0;
  for (int i = 0; i < 6; i++) {
    int count = 1;
    for (int j = 1; j < 4; j++) {
      if (copyCube[i][j] == copyCube[i][j - 1]) count++;
    }
    if (count == 4) fullSides++;
  }
  if (fullSides == 6) return true;
  return false;
}
void rl() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) copyCube[i][j] = cube[i][j];
  }
  copyCube[0][1] = cube[1][1];
  copyCube[0][3] = cube[1][3];
  copyCube[1][1] = cube[2][1];
  copyCube[1][3] = cube[2][3];
  copyCube[2][1] = cube[5][2];
  copyCube[2][3] = cube[5][0];
  copyCube[5][0] = cube[0][3];
  copyCube[5][2] = cube[0][1];
}
void rr() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) copyCube[i][j] = cube[i][j];
  }
  copyCube[1][1] = cube[0][1];
  copyCube[1][3] = cube[0][3];
  copyCube[2][1] = cube[1][1];
  copyCube[2][3] = cube[1][3];
  copyCube[5][2] = cube[2][1];
  copyCube[5][0] = cube[2][3];
  copyCube[0][3] = cube[5][0];
  copyCube[0][1] = cube[5][2];
}
void tl() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) copyCube[i][j] = cube[i][j];
  }
  copyCube[3][1] = cube[2][0];
  copyCube[3][3] = cube[2][1];
  copyCube[2][0] = cube[4][2];
  copyCube[2][1] = cube[4][0];
  copyCube[4][2] = cube[0][3];
  copyCube[4][0] = cube[0][2];
  copyCube[0][2] = cube[3][3];
  copyCube[0][3] = cube[3][1];
}
void tr() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) copyCube[i][j] = cube[i][j];
  }
  copyCube[2][0] = cube[3][1];
  copyCube[2][1] = cube[3][3];
  copyCube[4][2] = cube[2][0];
  copyCube[4][0] = cube[2][1];
  copyCube[0][3] = cube[4][2];
  copyCube[0][2] = cube[4][0];
  copyCube[3][3] = cube[0][2];
  copyCube[3][1] = cube[0][3];
}
void fl() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) copyCube[i][j] = cube[i][j];
  }
  copyCube[3][2] = cube[1][2];
  copyCube[3][3] = cube[1][3];
  copyCube[1][2] = cube[4][2];
  copyCube[1][3] = cube[4][3];
  copyCube[4][2] = cube[5][2];
  copyCube[4][3] = cube[5][3];
  copyCube[5][2] = cube[3][2];
  copyCube[5][3] = cube[3][3];
}
void fr() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) copyCube[i][j] = cube[i][j];
  }
  copyCube[5][2] = cube[4][2];
  copyCube[5][3] = cube[4][3];
  copyCube[4][2] = cube[1][2];
  copyCube[4][3] = cube[1][3];
  copyCube[1][2] = cube[3][2];
  copyCube[1][3] = cube[3][3];
  copyCube[3][2] = cube[5][2];
  copyCube[3][3] = cube[5][3];
}
int main() {
  for (int i = 0; i < 24; i++) {
    int side = i / 4;
    int num = i - side * 4;
    cin >> cube[side][num];
  }
  bool found = false;
  rl();
  if (check()) found = true;
  rr();
  if (check()) found = true;
  tl();
  if (check()) found = true;
  tr();
  if (check()) found = true;
  fl();
  if (check()) found = true;
  fr();
  if (check()) found = true;
  if (found)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
