#include <bits/stdc++.h>
using namespace std;
const int dim = 1003;
int tata[dim];
int h[dim];
int x[dim], y[dim];
int apartine[dim];
int n, m, k;
bool poz_start[dim], poz_stop[dim];
char str[dim];
unordered_map<string, int> nume_camera;
inline int gaseste_tatal(int u) {
  while (u != tata[u]) u = tata[u];
  return u;
}
inline void uneste(int u, int v) {
  u = gaseste_tatal(u);
  v = gaseste_tatal(v);
  if (u == v) return;
  if (h[u] == h[v]) {
    tata[v] = u;
    h[u]++;
  } else if (h[u] > h[v])
    tata[v] = u;
  else
    tata[u] = v;
}
inline bool au_acelasi_stramos(int u, int v) {
  int tata_u = gaseste_tatal(u);
  int tata_v = gaseste_tatal(v);
  return (tata_u == tata_v);
}
void dsu(bool* configuratie) {
  int i, j;
  for (i = 1; i <= n; ++i) tata[i] = i, h[i] = 1;
  for (i = 1; i <= m; ++i)
    for (j = 1; j <= m; ++j)
      if (au_acelasi_stramos(x[j], apartine[j]) == true ||
          au_acelasi_stramos(y[j], apartine[j]) == true) {
        uneste(x[j], y[j]);
        configuratie[j] = true;
      }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int i;
  int u, cnt, cheie, deschide;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) cin >> x[i] >> y[i];
  for (i = 1; i <= k; ++i) {
    cin >> str >> u >> cnt;
    nume_camera[string(str)] = u;
    while (cnt-- > 0) {
      cin >> deschide;
      apartine[deschide] = u;
    }
  }
  dsu(poz_start);
  for (i = 1; i <= k; ++i) {
    cin >> str >> u >> cnt;
    int tu = gaseste_tatal(u);
    if (gaseste_tatal(nume_camera[string(str)]) != tu) {
      cout << "NO";
      return 0;
    }
    while (cnt-- > 0) {
      cin >> deschide;
      if (gaseste_tatal(apartine[deschide]) != tu) {
        cout << "NO";
        return 0;
      }
      apartine[deschide] = u;
    }
  }
  dsu(poz_stop);
  for (i = 1; i <= m; ++i) {
    if (poz_start[i] != poz_stop[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
