#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > H;
map<pair<int, int>, int> ANS;
char s1[500011], s2[500011], s[500011];
inline void R(int &xx) {
  xx = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
}
inline void R(long long &xx) {
  xx = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
}
inline int change(char *s) {
  int tmp = 0, l = strlen(s + 1);
  for (int i = 1; i <= l; i++) tmp = tmp * 27 + s[i] - 'a' + 1;
  return tmp;
}
inline int Query() {
  scanf("%s %s", s1 + 1, s2 + 1);
  int ans = (1 << 30), t1 = change(s1), t2 = change(s2), l1 = strlen(s1 + 1),
      l2 = strlen(s2 + 1);
  if (!H.count(t1) || !H.count(t2)) return -1;
  if (H[t1].size() > H[t2].size()) swap(t1, t2), swap(l1, l2);
  if (ANS.count(make_pair(t1, t2))) return ANS[make_pair(t1, t2)];
  for (int i = 0; i < H[t1].size(); i++) {
    int y =
        lower_bound((H[t2]).begin(), (H[t2]).end(), H[t1][i]) - H[t2].begin();
    if (y >= 0 && y < H[t2].size())
      ans =
          min(ans, max(H[t2][y] + l2, H[t1][i] + l1) - min(H[t1][i], H[t2][y]));
    y--;
    if (y >= 0 && y < H[t2].size())
      ans =
          min(ans, max(H[t2][y] + l2, H[t1][i] + l1) - min(H[t1][i], H[t2][y]));
  }
  return ANS[make_pair(t1, t2)] = ANS[make_pair(t2, t1)] = ans;
}
int main() {
  scanf("%s", s + 1);
  int T, n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    int tmp = 0;
    for (int j = 0; j < 4; j++) {
      if (i + j > n) break;
      tmp = tmp * 27 + s[i + j] - 'a' + 1;
      H[tmp].push_back(i);
    }
  }
  R(T);
  while (T--) printf("%d\n", Query());
  return 0;
}
