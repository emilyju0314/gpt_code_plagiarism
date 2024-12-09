#include <bits/stdc++.h>
using namespace std;
vector<int> E[1110000];
struct Trie {
  int ck;
  int ch[26];
} T[1110000];
int cnt, n, par[1110000];
char p[1110000];
vector<string> P;
void init(int a) {
  for (int i = 0; i < 26; i++) T[a].ch[i] = 0;
}
void Ins(int a, char *key) {
  if (!(*key)) {
    return;
  }
  int ck = (*key) - 'a';
  if (!T[a].ch[ck]) {
    T[a].ch[ck] = ++cnt;
    init(cnt);
    T[cnt].ck = ck;
  }
  Ins(T[a].ch[ck], key + 1);
}
void Make(int r1, int r2, char *key) {
  if (!r1 || !r2) return;
  if (r1 != 1) {
    if (!par[r2]) {
      par[r2] = r1;
      E[r1].push_back(r2);
      E[r2].push_back(r1);
    }
  }
  if (!(*key)) return;
  int ck = (*key) - 'a';
  Make(T[r1].ch[ck], T[r2].ch[ck], key + 1);
}
int D[1110000][2], v[1110000];
void DFS(int a, int pp) {
  v[a] = 1;
  int i, x, s = 0, s2 = 0;
  for (i = 0; i < E[a].size(); i++) {
    x = E[a][i];
    if (x == pp) continue;
    DFS(x, a);
    s += D[x][1];
    s2 += D[x][0];
  }
  D[a][0] = s;
  D[a][1] = max(s2 + 1, s);
}
int main() {
  int i, TC, j;
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d", &n);
    P.resize(n);
    cnt = 1;
    init(1);
    for (i = 0; i < n; i++) {
      scanf("%s", p);
      Ins(1, p);
      P[i] = p;
    }
    for (i = 1; i <= cnt; i++) E[i].clear(), v[i] = 0, par[i] = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < P[i].size(); j++) {
        p[j] = P[i][j];
      }
      p[j] = 0;
      Make(1, T[1].ch[p[0] - 'a'], p + 1);
    }
    int res = 0;
    for (i = 2; i <= cnt; i++) {
      if (!v[i]) {
        DFS(i, 0);
        res += D[i][1];
      }
    }
    printf("%d\n", res);
  }
}
