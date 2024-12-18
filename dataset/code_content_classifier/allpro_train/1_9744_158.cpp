#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 4;
char s[maxn];
int a[maxn];
void get(bitset<maxn> &B) {
  scanf("%s", s);
  int m = strlen(s);
  for (int i = 0; i < m; i++) a[m - 1 - i] = s[i] - '0';
  m--;
  for (int i = 0; i < maxn; i++) {
    if (m < 0) break;
    int rem = 0;
    for (int j = m; j >= 0; j--) a[j] += rem * 10, rem = (a[j] & 1), a[j] >>= 1;
    B[i] = rem;
    while (m >= 0 && !a[m]) m--;
  }
}
int pos[maxn];
bitset<maxn> b[maxn], st[maxn];
int main() {
  if (fopen("in", "r")) {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  }
  memset(pos, -1, sizeof(pos));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    get(b[i]);
    st[i][i] = 1;
    bool ok = 1;
    for (int j = 0; j < maxn; j++)
      if (b[i][j]) {
        if (pos[j] == -1) {
          ok = 0;
          pos[j] = i;
          break;
        }
        b[i] ^= b[pos[j]];
        st[i] ^= st[pos[j]];
      }
    if (!ok) {
      printf("0\n");
      continue;
    }
    st[i][i] = 0;
    printf("%d", st[i].count());
    for (int j = 0; j < maxn; j++)
      if (st[i][j]) printf(" %d", j);
    printf("\n");
  }
}
