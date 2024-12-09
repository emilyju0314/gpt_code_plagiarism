#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
bool del[1000006];
vector<int> ed[1000006], ans;
int main() {
  scanf("%d%d", &n, &m);
  for (; m--;) scanf("%d%d", &u, &v), ed[u].push_back(v);
  for (int i = 1; i <= n; i++)
    if (!del[i])
      for (auto j : ed[i])
        if (j > i) del[j] = 1;
  for (int i = n; i; i--)
    if (!del[i]) {
      ans.push_back(i);
      for (auto j : ed[i]) del[j] = 1;
    }
  printf("%d\n", ans.size());
  for (auto i : ans) printf("%d ", i);
}
