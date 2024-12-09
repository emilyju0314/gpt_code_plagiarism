#include <bits/stdc++.h>
using namespace std;
char M[101][101];
int A[27];
int main() {
  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  bool sentido;
  if (a % 2 == 0)
    sentido = 1;
  else
    sentido = 0;
  int col = 0, fil, val = 0, pintados = 0, lim;
  while (col < a + c) {
    sentido = 1 - sentido;
    if (col < a)
      lim = b - 1;
    else
      lim = d - 1;
    if (sentido == 0)
      fil = 0;
    else
      fil = lim;
    while (fil >= 0 && fil <= lim) {
      M[fil][col] = val + 'a';
      pintados++;
      if (pintados == A[val]) {
        pintados = 0;
        val++;
      }
      if (sentido == 0) {
        fil++;
      } else
        fil--;
    }
    col++;
  }
  for (int i = 0; i < max(b, d); ++i) {
    for (int j = 0; j < a + c; ++j) {
      if (!(M[i][j] >= 'a' && M[i][j] <= (val - 1 + 'a'))) M[i][j] = '.';
    }
  }
  puts("YES");
  for (int i = 0; i < max(b, d); ++i) {
    for (int j = 0; j < a + c; ++j) {
      cout << M[i][j];
    }
    puts("");
  }
}
