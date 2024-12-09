#include <bits/stdc++.h>
using namespace std;
const int INF = -1u / 2;
map<int, int> M;
map<int, int>::iterator it;
int node[1010];
struct xx {
  int val, tar;
  bool operator<(const xx& T) const { return val < T.val; }
} th;
priority_queue<xx> H;
struct xxx {
  int tar, l, r;
} tv;
vector<xxx> edge[1010];
int n, m;
int cal[7010];
int main() {
  int a, b, l, r;
  scanf("%d%d", &n, &m);
  for (int c = 1; c <= m; c++) {
    scanf("%d%d%d%d", &a, &b, &l, &r);
    M[l] = true;
    M[r] = true;
    tv.l = l;
    tv.r = r;
    tv.tar = a;
    edge[b].push_back(tv);
    tv.tar = b;
    edge[a].push_back(tv);
  }
  int cc = 1;
  for (it = M.begin(); it != M.end(); it++) {
    it->second = cc;
    cal[cc] = it->first;
    cc++;
  }
  for (int c = 1; c <= n; c++) {
    for (int d = 0; d < edge[c].size(); d++) {
      edge[c][d].l = M[edge[c][d].l];
      edge[c][d].r = M[edge[c][d].r];
    }
  }
  int si = M.size();
  int sol = 0, x;
  for (int c = 1; c <= si; c++) {
    node[1] = INF;
    for (int d = 2; d <= n; d++) node[d] = 0;
    while (!H.empty()) H.pop();
    th.tar = 1;
    th.val = INF;
    H.push(th);
    while (!H.empty()) {
      th = H.top();
      H.pop();
      a = th.tar;
      b = th.val;
      if (th.tar == n) {
        sol = max(sol, cal[b] - cal[c] + 1);
        break;
      }
      for (int d = 0; d < edge[a].size(); d++) {
        if (c >= edge[a][d].l) {
          x = min(b, edge[a][d].r);
          if (x > node[edge[a][d].tar]) {
            node[edge[a][d].tar] = x;
            th.tar = edge[a][d].tar;
            th.val = x;
            H.push(th);
          }
        }
      }
    }
  }
  if (sol == 0)
    printf("Nice work, Dima!");
  else
    printf("%d", sol);
}
