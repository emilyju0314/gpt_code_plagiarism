#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100010;
int T, n, op;
char ss[N];
int s[N], a[N];
bool find_it;
int dp[N][2][2];
int dfs(int l, int r, int nl, int nr) {
  if (dp[l][nl][nr] != -1) return dp[l][nl][nr];
  if (l > r) {
    if (nl == nr && (a[l] + a[r] + nl) / 10 == nl) find_it = true;
    return find_it;
  }
  int st = 0;
  if (op == 1 && l == 1) st = 1;
  if (op == 2 && l == 2) st = 1;
  if (l == r) {
    for (int v = st; v <= 9; v++) {
      int val = v * 2 + nr;
      if (val % 10 != s[l]) continue;
      if ((nl == 1 && val >= 10) || (nl == 0 && val < 10)) {
        a[l] = v;
        find_it = true;
        break;
      }
    }
    return find_it;
  }
  for (int lnum = st; lnum <= 9 && find_it == false; lnum++) {
    for (int next_nl = 0; next_nl <= 1 && find_it == false; next_nl++) {
      int rnum;
      if (next_nl == 0 && nl == 0)
        rnum = s[l] - lnum;
      else if (next_nl == 0 && nl == 1)
        rnum = 10 + s[l] - lnum;
      else if (next_nl == 1 && nl == 0)
        rnum = s[l] - 1 - lnum;
      else if (next_nl == 1 && nl == 1)
        rnum = 9 + s[l] - lnum;
      else
        continue;
      if (rnum > 9 || rnum < 0) continue;
      if ((lnum + rnum + nr) % 10 != s[r]) continue;
      int next_nr = (lnum + rnum + nr) / 10;
      a[l] = lnum, a[r] = rnum;
      dfs(l + 1, r - 1, next_nl, next_nr);
    }
  }
  return dp[l][nl][nr] = find_it;
}
int main() {
  while (~scanf("%s", ss + 1)) {
    n = strlen(ss + 1);
    for (int i = 1; i <= n; i++) s[i] = ss[i] - '0';
    if (n == 1 && s[1] == 1) {
      printf("0\n");
      continue;
    }
    memset(dp, -1, sizeof(dp));
    find_it = false;
    op = 1;
    dfs(1, n, 0, 0);
    if (find_it == true) {
      for (int i = 1; i <= n; i++) printf("%d", a[i]);
      puts("");
      continue;
    }
    if (s[1] == 1) {
      memset(dp, -1, sizeof(dp));
      op = 2;
      dfs(2, n, 1, 0);
      if (find_it == true) {
        for (int i = 2; i <= n; i++) printf("%d", a[i]);
        puts("");
        continue;
      }
    }
    printf("0\n");
  }
  return 0;
}
