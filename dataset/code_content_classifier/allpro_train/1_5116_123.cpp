#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 110;
char c[N], s[M], t[N];
int trie[M][26], word[M], f[N][M], cnt, fail[M];
void insert(char *s, int v) {
  int len = strlen(s);
  int p = 0;
  for (int i = 0; i < len; i++) {
    int u = s[i] - 'a';
    if (!trie[p][u]) trie[p][u] = ++cnt;
    p = trie[p][u];
  }
  word[p] += v;
}
void build() {
  queue<int> q;
  for (int i = 0; i < 26; i++)
    if (trie[0][i]) q.push(trie[0][i]);
  while (q.size()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < 26; i++)
      if (trie[now][i]) {
        fail[trie[now][i]] = trie[fail[now]][i];
        q.push(trie[now][i]);
      } else
        trie[now][i] = trie[fail[now]][i];
    word[now] += word[fail[now]];
  }
}
int main() {
  scanf("%s%s%s", c, s, t);
  insert(s, 1);
  insert(t, -1);
  build();
  memset(f, -0x3f, sizeof f);
  f[0][0] = 0;
  int len = strlen(c);
  for (int i = 0; i < len; i++)
    for (int j = 0; j <= cnt; j++)
      for (int k = 0; k < 26; k++)
        if (c[i] == '*' || 'a' + k == c[i]) {
          int id = trie[j][k];
          f[i + 1][id] = max(f[i + 1][id], f[i][j] + word[id]);
        }
  int ans = -0x3f3f3f3f;
  for (int i = 0; i <= cnt; i++) ans = max(ans, f[len][i]);
  printf("%d\n", ans);
  return 0;
}
