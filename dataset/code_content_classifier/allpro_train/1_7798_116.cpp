#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, T b) {
  return b > a ? a = b, 1 : 0;
}
inline int read() {
  int x(0), sgn(1);
  char ch(getchar());
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
  return x * sgn;
}
void File() {}
unordered_map<string, int> M[10], id[10];
set<string> S;
string str[10010];
int main() {
  File();
  int n = read();
  for (register int i = (1), iend = (int)(n); i <= iend; ++i) {
    cin >> str[i];
    S.clear();
    for (register int j = (0), jend = (int)(str[i].size() - 1); j <= jend;
         ++j) {
      string tmp = "";
      for (register int k = (j), kend = (int)(str[i].size() - 1); k <= kend;
           ++k)
        tmp += str[i][k], S.insert(tmp);
    }
    for (string cur : S) {
      ++M[cur.size()][cur], id[cur.size()][cur] = i;
    }
  }
  int q = read();
  while (q--) {
    string cur;
    cin >> cur;
    int ans = M[cur.size()][cur];
    if (!ans) {
      puts("0 -");
      continue;
    }
    printf("%d %s\n", ans, str[id[cur.size()][cur]].c_str());
  }
  return 0;
}
