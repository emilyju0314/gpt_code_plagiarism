#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int MAXN = 1000001;
const int BASE = (int)1e9 + 7;
const int BLOCK = 450;
const long double EPS = (long double)1e-9;
char s[MAXN];
char t[MAXN];
int q;
int lstS[MAXN];
int prefS[MAXN];
int prefAS[MAXN];
int lstT[MAXN];
int prefT[MAXN];
int prefAT[MAXN];
void init(char *s, int n, int *lst, int *pref, int *prefA) {
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1];
    prefA[i] = prefA[i - 1];
    if (s[i] == 'A') {
      prefA[i]++;
      lst[i] = lst[i - 1] + 1;
    } else {
      pref[i]++;
    }
  }
}
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  init(s, n, lstS, prefS, prefAS);
  scanf("%s", t + 1);
  int m = strlen(t + 1);
  init(t, m, lstT, prefT, prefAT);
  scanf("%d", &q);
  while (q--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int cntS = prefS[b] - prefS[a - 1];
    int cntAS = min(lstS[b], b - a + 1);
    int addS = prefAS[b] - prefAS[a - 1];
    int cntT = prefT[d] - prefT[c - 1];
    int cntAT = min(lstT[d], d - c + 1);
    int addT = prefAT[d] - prefAT[c - 1];
    if (cntAS < cntAT) {
      cout << '0';
      continue;
    }
    cntAS -= cntAT;
    if (cntS == cntT) {
      cout << (cntAS % 3 == 0 ? '1' : '0');
    } else if (cntS < cntT) {
      if (cntAS) {
        cntS += 2;
      }
      cout << (cntS <= cntT && cntS % 2 == cntT % 2 && cntS != 0 ? '1' : '0');
    } else if (cntS > cntT) {
      cout << '0';
    }
  }
  return 0;
}
