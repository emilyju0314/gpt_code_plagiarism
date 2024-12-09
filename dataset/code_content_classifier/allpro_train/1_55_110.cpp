#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
inline int R() {
  int rt = 0;
  char ch = getchar();
  bool isn = false;
  for (; ch < '0' || ch > '9'; ch = getchar()) isn = ch == '-' ? true : isn;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) rt = rt * 10 + ch - '0';
  return isn ? -rt : rt;
}
vector<int> e[MAXN];
int sz[MAXN];
vector<int> ans;
bool u[MAXN];
void Pre(int nf, int nfa) {
  sz[nf] = 1;
  for (vector<int>::iterator ne = e[nf].begin(); ne != e[nf].end(); ++ne) {
    if (*ne == nfa) continue;
    Pre(*ne, nf);
    sz[nf] += sz[*ne];
  }
}
void Dfs(int nf, int nfa) {
  for (vector<int>::iterator ne = e[nf].begin(); ne != e[nf].end(); ++ne) {
    if (*ne == nfa) continue;
    if (!(sz[*ne] & 1)) Dfs(*ne, nf);
  }
  u[nf] = true;
  ans.push_back(nf);
  for (vector<int>::iterator ne = e[nf].begin(); ne != e[nf].end(); ++ne) {
    if (*ne == nfa) continue;
    if (!u[*ne]) Dfs(*ne, nf);
  }
}
int main() {
  int n = R();
  if (!(n & 1)) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    int nv = R();
    if (nv) e[nv].push_back(i), e[i].push_back(nv);
  }
  Pre(1, 0);
  Dfs(1, 0);
  puts("YES");
  for (vector<int>::iterator nans = ans.begin(); nans != ans.end(); ++nans)
    printf("%d\n", *nans);
  return 0;
}
