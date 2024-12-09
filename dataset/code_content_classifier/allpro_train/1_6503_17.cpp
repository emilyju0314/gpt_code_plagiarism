#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000009;
const double pi = atan(1.0) * 4.0;
const double eps = 1e-8;
const int N = 2005;
const int M = 20;
int i, j, k, m, n, l, q, I;
int bc[1 << M];
int ones[N];
int a[N][N / M + 1];
inline int hasit(int a, int b) { return (a | b) != b; }
inline int findit(int a, int b) {
  for (int k = 0; k < M; k++)
    if ((a & (1 << k)) && !(b & (1 << k))) {
      return k;
    }
  return 0;
}
set<pair<int, int> > S;
set<int> yes;
int d[N][N], dones[N];
void checkadd(const set<pair<int, int> >::iterator& it) {
  auto it2 = it;
  it2++;
  if (it2 != S.end()) {
    if (it2 == S.end()) throw;
    int i = it->second;
    int j = it2->second;
    int has0 = 0, has1 = 0;
    for (int k = 0; k < n / M + 1; k++) {
      has0 |= hasit(a[i][k], a[j][k]);
      has1 |= hasit(a[j][k], a[i][k]);
    }
    if (has0 && has1) {
      if (I == 7) {
        cerr << "!!!" << i << " " << j << "  " << it->first << " " << it2->first
             << endl;
      }
      yes.insert(i);
    }
  }
}
int main() {
  for (int i = 0; i < (1 << M); i++)
    if (i) bc[i] = bc[i & (i - 1)] + 1;
  int all = (1 << M) - 1;
  cin >> m >> n >> q;
  for (int i = 0; i < m; i++) S.insert(pair<int, int>(0, i));
  int row, L, R;
  while (q--) {
    I++;
    scanf("%d%d%d", &row, &L, &R);
    row--;
    L--;
    R--;
    if (0) {
      for (int i = L; i <= R; i++) {
        d[row][i] ^= 1;
      }
      dones[row] = 0;
      for (int i = 0; i < n; i++) dones[row] += d[row][i];
    }
    int tocheck = -1;
    yes.erase(row);
    set<pair<int, int> >::iterator it = S.find(pair<int, int>(ones[row], row));
    if (it != S.begin()) {
      set<pair<int, int> >::iterator it2 = it;
      it2--;
      yes.erase(it2->second);
      tocheck = it2->second;
    }
    S.erase(it);
    for (int i = L / M + 1; i <= R / M - 1; i++) {
      ones[row] -= bc[a[row][i]];
      a[row][i] ^= all;
      ones[row] += bc[a[row][i]];
    }
    for (int i = 0; i < M; i++) {
      int ind = M * (L / M) + i;
      if (ind >= L && ind <= R) {
        ones[row] -= (a[row][L / M] & (1 << i)) > 0;
        a[row][L / M] ^= (1 << i);
        ones[row] += (a[row][L / M] & (1 << i)) > 0;
      }
    }
    if (L / M != R / M) {
      for (int i = 0; i < M; i++) {
        int ind = M * (R / M) + i;
        if (ind >= L && ind <= R) {
          ones[row] -= (a[row][R / M] & (1 << i)) > 0;
          a[row][R / M] ^= (1 << i);
          ones[row] += (a[row][R / M] & (1 << i)) > 0;
        }
      }
    }
    if (0) {
      for (int i = 0; i < m; i++)
        if (dones[i] != ones[i]) {
          cerr << dones[i] << " " << ones[i] << endl;
          cerr << "ones" << endl;
          throw;
        }
    }
    S.insert(pair<int, int>(ones[row], row));
    it = S.find(pair<int, int>(ones[row], row));
    if (it != S.begin()) {
      set<pair<int, int> >::iterator it2 = it;
      it2--;
      yes.erase(it2->second);
      checkadd(it2);
    }
    checkadd(it);
    if (tocheck != -1) {
      checkadd(S.find(pair<int, int>(ones[tocheck], tocheck)));
    }
    if (yes.empty()) {
      printf("-1\n");
    } else {
      int i = *yes.begin();
      auto it = S.find(pair<int, int>(ones[i], i));
      it++;
      int j = it->second;
      int c0 = -1, c1 = -1;
      for (int u = 0; u < (n / M + 1); u++) {
        if (c0 == -1 && hasit(a[i][u], a[j][u])) {
          c0 = findit(a[i][u], a[j][u]) + u * M;
        }
        if (c1 == -1 && hasit(a[j][u], a[i][u])) {
          c1 = findit(a[j][u], a[i][u]) + u * M;
        }
      }
      if (i > j) swap(i, j);
      if (c0 > c1) swap(c0, c1);
      if (0) {
        if (d[i][c0] == d[j][c1] && d[i][c0] != d[j][c0] &&
            d[i][c0] != d[i][c1])
          ;
        else {
          cout << "wrong ";
        }
      }
      printf("%d %d %d %d\n", i + 1, c0 + 1, j + 1, c1 + 1);
    }
  }
  return 0;
}
