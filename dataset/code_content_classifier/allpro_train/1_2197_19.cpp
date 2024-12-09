#include <bits/stdc++.h>
using namespace std;
const int nMax = 200010;
char s[nMax], t[nMax];
int L[nMax], R[nMax], last[30];
int main() {
  int ls, lt, i, j, k;
  while (scanf("%s%s", s, t) == 2) {
    ls = strlen(s);
    lt = strlen(t);
    memset(last, -1, sizeof(last));
    for (i = 0, k = 0; i < ls; i++) {
      if (s[i] == t[k]) k++;
      L[i] = k - 1;
    }
    for (i = ls - 1, k = lt - 1; i >= 0; i--) {
      if (k >= 0 && s[i] == t[k]) k--;
      R[i] = k + 1;
    }
    for (i = 0; i < ls; i++) {
      if (L[i] >= 0) last[t[L[i]] - 'a'] = L[i];
      if (last[s[i] - 'a'] < 0 || last[s[i] - 'a'] < R[i]) goto WA;
    }
    printf("Yes\n");
    continue;
  WA:
    printf("No\n");
  }
}
