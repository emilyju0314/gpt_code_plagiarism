#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<int> ind[N];
priority_queue<int> q;
long long ans[N * 10];
int main() {
  int n, m, ct, cx;
  scanf("%d%d", &n, &m);
  long long t = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &ct, &cx);
    ind[cx].push_back(i);
    q.push(-cx);
    if (q.size() == m || i == n - 1) {
      t = max(t, ct * 1ll);
      int last = 0;
      while (!q.empty()) {
        int x = -q.top();
        q.pop();
        if (last == x) continue;
        t += x - last;
        last = x;
        for (int j = 0; j < ind[x].size(); j++) ans[ind[x][j]] = t;
        t += 1 + ind[x].size() / 2;
        ind[x].clear();
      }
      t += last;
    }
  }
  for (int i = 0; i < n; i++) printf("%I64d ", ans[i]);
  return 0;
}
