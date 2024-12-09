#include <bits/stdc++.h>
using namespace std;
int L1, L2;
int v[1000000 + 1], pos[1000000 + 1];
bool valid(int p, int q, int nq) {
  if (nq == -1)
    return 0;
  else {
    if (p > q) q += L2;
    if (q > nq) nq += L2;
    return p <= q && q <= nq && nq - p < L2;
  }
}
int main() {
  while (scanf("%d %d", &L1, &L2) == 2) {
    for (int i = 0; i < L1; i++) scanf("%d", &v[i]);
    memset(pos, -1, sizeof(pos));
    for (int i = 0; i < L2; i++) {
      int tmp;
      scanf("%d", &tmp);
      pos[tmp] = i;
    }
    int i = 0, maxN = 0;
    while (i < L1 && pos[v[i]] == -1) i++;
    if (i == L1)
      cout << 0 << endl;
    else {
      int p = pos[v[i]], q = pos[v[i]], j = i;
      maxN = 1;
      while (i < L1) {
        p = pos[v[i]];
        if (p != -1) {
          if (j < i) {
            j = i;
            q = pos[v[j % L1]];
          }
          while (j + 1 - i < L1 && valid(p, q, pos[v[(j + 1) % L1]])) {
            j = j + 1;
            q = pos[v[j % L1]];
            maxN = max(maxN, j - i + 1);
          }
        }
        i++;
      }
      cout << maxN << endl;
    }
  }
  return 0;
}
