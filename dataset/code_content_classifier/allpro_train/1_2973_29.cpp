#include <bits/stdc++.h>
using namespace std;
int n;
bool f2[303][303];
bool c1[303], c2[303];
bool C2[603];
string solve2() {
  memset(c1, 1, sizeof c1);
  memset(c2, 1, sizeof c2);
  memset(C2, 1, sizeof C2);
  c1[0] = c2[0] = 0;
  int a1, a2;
  cin >> a1 >> a2;
  for (int i = 0; i <= a1; i++)
    for (int j = 0; j <= a2; j++) {
      f2[i][j] |= !C2[i - j + 300];
      if (i) f2[i][j] |= !c2[j];
      if (j) f2[i][j] |= !c1[i];
      c2[j] &= f2[i][j];
      c1[i] &= f2[i][j];
      C2[i - j + 300] &= f2[i][j];
    }
  return f2[a1][a2] ? "BitLGM" : "BitAryo";
}
bool f3[303][303][303];
bool c12[303][303], c23[303][303], c13[303][303];
bool C3[603][603];
string solve3() {
  memset(c12, 1, sizeof c12);
  memset(c23, 1, sizeof c23);
  memset(c13, 1, sizeof c13);
  memset(C3, 1, sizeof C3);
  c12[0][0] = c13[0][0] = c23[0][0] = 0;
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  for (int i = 0; i <= a1; i++)
    for (int j = 0; j <= a2; j++)
      for (int k = 0; k <= a3; k++) {
        int l = min(i, min(j, k));
        f3[i][j][k] |= !C3[i - j + 300][i - k + 300];
        if (l > 1) f3[i][j][k] |= !f3[i - l + 1][j - l + 1][k - l + 1];
        if (i) f3[i][j][k] |= !c23[j][k];
        if (j) f3[i][j][k] |= !c13[i][k];
        if (k) f3[i][j][k] |= !c12[i][j];
        c23[j][k] &= f3[i][j][k];
        c13[i][k] &= f3[i][j][k];
        c12[i][j] &= f3[i][j][k];
        C3[i - j + 300][i - k + 300] &= f3[i][j][k];
      }
  return f3[a1][a2][a3] ? "BitLGM" : "BitAryo";
}
int main() {
  cin >> n;
  if (n == 1) {
    int a1;
    cin >> a1;
    if (a1)
      cout << "BitLGM";
    else
      cout << "BitAryo";
  } else if (n == 2)
    cout << solve2();
  else
    cout << solve3();
  return 0;
}
