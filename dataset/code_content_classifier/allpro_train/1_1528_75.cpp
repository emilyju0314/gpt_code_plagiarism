#include <bits/stdc++.h>
using namespace std;
int D, N, M, Ct, Cl, Cr, Cb, X1, Y1, X2, Y2, cnt = 0, fr[5][100005];
struct sofa {
  int maxx, minx, maxy, miny;
} v[100005];
int main() {
  cin >> D >> N >> M;
  for (int i = 1; i <= D; i++) {
    cin >> X1 >> Y1 >> X2 >> Y2;
    v[i].maxx = max(X1, X2);
    v[i].minx = min(X1, X2);
    v[i].maxy = max(Y1, Y2);
    v[i].miny = min(Y1, Y2);
    fr[1][min(X1, X2)]++;
    fr[2][max(X1, X2)]++;
    fr[3][min(Y1, Y2)]++;
    fr[4][max(Y1, Y2)]++;
  }
  cin >> Cl >> Cr >> Ct >> Cb;
  for (int i = 1; i <= N + 1; i++) fr[1][i] += fr[1][i - 1];
  for (int i = N + 1; i > 0; i--) fr[2][i] += fr[2][i + 1];
  for (int i = 1; i <= M + 1; i++) fr[3][i] += fr[3][i - 1];
  for (int i = M + 1; i > 0; i--) fr[4][i] += fr[4][i + 1];
  for (int i = 1; i <= D; i++) {
    if (fr[1][v[i].maxx - 1] - (int)(v[i].maxx != v[i].minx) == Cl &&
        fr[2][v[i].minx + 1] - (int)(v[i].maxx != v[i].minx) == Cr &&
        fr[3][v[i].maxy - 1] - (int)(v[i].maxy != v[i].miny) == Ct &&
        fr[4][v[i].miny + 1] - (int)(v[i].maxy != v[i].miny) == Cb) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
