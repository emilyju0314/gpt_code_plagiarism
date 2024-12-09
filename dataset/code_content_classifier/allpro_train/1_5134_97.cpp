#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 5;
int N, K, S, clu[MAXN], pos[MAXN];
int out[2 * MAXN][2], cnt;
int main() {
  scanf("%d%d", &N, &K);
  memset(clu, 0, sizeof(clu));
  int c = 0;
  for (int i = 1; i <= K; i++) {
    scanf("%d", &S);
    for (int j = 1; j <= S; j++) {
      int p;
      scanf("%d", &p);
      c++;
      clu[p] = c;
      pos[c] = p;
    }
  }
  int s = 0;
  for (;; s++) {
    bool flag = 0;
    for (int i = 1; i <= c; i++) {
      int p = pos[i];
      if (p != i && !clu[i]) {
        pos[i] = i;
        clu[i] = i;
        clu[p] = 0;
        cnt++;
        out[cnt][0] = p;
        out[cnt][1] = i;
        flag = 1;
      }
    }
    if (!flag) {
      int x, p, q;
      for (int i = 1; i <= c; i++)
        if (pos[i] != i) {
          x = i;
          p = pos[i];
          flag = 1;
          break;
        }
      for (int i = 1; i <= N; i++)
        if (!clu[i]) {
          q = i;
          break;
        }
      if (!flag) break;
      pos[x] = q;
      clu[q] = x;
      clu[p] = 0;
      cnt++;
      out[cnt][0] = p;
      out[cnt][1] = q;
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d %d\n", out[i][0], out[i][1]);
  return 0;
}
