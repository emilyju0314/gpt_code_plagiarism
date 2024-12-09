#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3 * 100010;
int v[MAXN][3];
vector<int> qperm;
int nxt[MAXN], prv[MAXN];
set<int> cnt[MAXN];
int N, Q;
void solve(queue<int> &cnt1) {
  int t = cnt1.front();
  cnt1.pop();
  if (cnt[t].size() != 1) return;
  int qi = *cnt[t].begin();
  int a = -1, b = -1;
  for (int i = 0; i < 3; ++i) {
    cnt[v[qi][i]].erase(qi);
    if (cnt[v[qi][i]].size() == 1) cnt1.push(v[qi][i]);
    if (v[qi][i] != t) {
      if (a < 0)
        a = v[qi][i];
      else
        b = v[qi][i];
    }
  }
  qperm.push_back(qi);
  solve(cnt1);
  if (nxt[a] < 0) {
    nxt[a] = t;
    prv[t] = a;
    nxt[t] = b;
    prv[b] = t;
    nxt[b] = a;
    prv[a] = b;
  } else {
    if (nxt[a] != b) swap(a, b);
    assert(nxt[a] == b);
    nxt[a] = t;
    prv[t] = a;
    nxt[t] = b;
    prv[b] = t;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    qperm.clear();
    scanf("%d", &N);
    Q = N - 2;
    for (int i = 0; i < N; ++i) cnt[i].clear(), nxt[i] = prv[i] = -1;
    for (int i = 0; i < Q; ++i) {
      scanf("%d%d%d", &v[i][0], &v[i][1], &v[i][2]);
      --v[i][0], --v[i][1], --v[i][2];
      for (int z = 0; z < 3; ++z) cnt[v[i][z]].insert(i);
    }
    queue<int> cnt1;
    for (int i = 0; i < N; ++i)
      if (cnt[i].size() == 1) cnt1.push(i);
    solve(cnt1);
    putchar('1');
    for (int i = nxt[0]; i != 0; i = nxt[i]) printf(" %d", i + 1);
    puts("");
    for (const auto &it : qperm) printf("%d ", it + 1);
    puts("");
  }
  return 0;
}
