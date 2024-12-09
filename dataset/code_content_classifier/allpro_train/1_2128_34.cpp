#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int ch[maxn][26], End[maxn], fail[maxn];
int num[maxn], q[maxn], head, tail, cnt;
char c[maxn];
void insert(int opt) {
  int Now = 0;
  for (int i = 1; c[i]; i++) {
    if (!ch[Now][c[i] - 'a']) ch[Now][c[i] - 'a'] = ++cnt;
    Now = ch[Now][c[i] - 'a'];
  }
  End[Now] += num[opt];
}
void failbuild() {
  for (int i = 0; i < 26; i++)
    if (ch[0][i]) q[++head] = ch[0][i];
  while (tail < head) {
    int Now = q[++tail];
    End[Now] += End[fail[Now]];
    for (int i = 0; i < 26; i++) {
      if (ch[Now][i]) {
        q[++head] = ch[Now][i];
        fail[ch[Now][i]] = ch[fail[Now]][i];
      } else
        ch[Now][i] = ch[fail[Now]][i];
    }
  }
}
struct mat {
  long long mp[maxn][maxn];
  mat() {}
  mat(long long x) {
    for (int i = 0; i <= cnt; i++)
      for (int j = 0; j <= cnt; j++) mp[i][j] = x;
  }
  mat friend operator*(mat a, mat b) {
    mat res(-1);
    for (int k = 0; k <= cnt; k++)
      for (int i = 0; i <= cnt; i++)
        for (int j = 0; j <= cnt; j++) {
          if (a.mp[i][k] != -1 && b.mp[k][j] != -1)
            res.mp[i][j] = max(res.mp[i][j], a.mp[i][k] + b.mp[k][j]);
        }
    return res;
  }
  mat friend operator^(mat a, long long x) {
    mat res(-1);
    res.mp[0][0] = 0;
    while (x) {
      if (x & 1) res = res * a;
      a = a * a;
      x >>= 1;
    }
    return res;
  }
};
mat a;
void failmat() {
  for (int i = 0; i <= cnt; i++)
    for (int j = 0; j <= cnt; j++) a.mp[i][j] = -1;
  for (int i = 0; i <= cnt; i++) {
    for (int j = 0; j < 26; j++) a.mp[i][ch[i][j]] = End[ch[i][j]];
  }
}
int main() {
  int N, i, j;
  long long L, Max = 0;
  scanf("%d%I64d", &N, &L);
  for (i = 1; i <= N; i++) scanf("%d", &num[i]);
  for (i = 1; i <= N; i++) {
    scanf("%s", c + 1);
    insert(i);
  }
  failbuild();
  failmat();
  mat ans = a ^ L;
  for (i = 0; i <= cnt; i++) Max = max(Max, ans.mp[0][i]);
  printf("%I64d\n", Max);
  return 0;
}
