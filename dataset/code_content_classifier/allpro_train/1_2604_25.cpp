#include <bits/stdc++.h>
using namespace std;
int T, a, b, i, X, Y, R[3333];
struct A {
  int x, y, r, num;
};
struct B {
  double f;
  int ind;
} st[12666];
bool cmp(B aa, B bb) { return aa.f < bb.f; }
void solve(vector<A> G) {
  int m = 0;
  for (int k = 0; k < G.size(); k++)
    if (G[m].r < G[k].r) m = k;
  if (G[m].r == 1) {
    for (int k = 0; k < G.size(); k++)
      if (G[k].r == 0) m = k;
    for (int k = 0; k < G.size(); k++) {
      if (k != m) {
        printf("%d %d\n", G[k].num, G[m].num);
      }
    }
    return;
  }
  int sz = 0, o, ch[6666] = {};
  int acnt = 0, bcnt = 0, rcnt = 0;
  for (int k = 0; k < G.size(); k++)
    if (k != m) {
      double ta = atan2(G[k].y - G[m].y, G[k].x - G[m].x);
      st[sz++] = {ta, k};
      if (ta > 0) {
        ta -= atan2(0, -1);
        rcnt += G[k].r;
        if (G[k].r == 0)
          acnt++;
        else
          bcnt++;
        ch[k] = 1;
      } else
        ta += atan2(0, -1);
      st[sz++] = {ta, -k - 1};
    }
  sort(st, st + sz, cmp);
  vector<A> D1, D2;
  for (int k = 0; k < sz; k++) {
    if (acnt + bcnt - rcnt > 0 && acnt + bcnt - rcnt < G[m].r) {
      o = acnt + bcnt - rcnt;
      for (int l = 0; l < G.size(); l++)
        if (l != m) {
          if (ch[l])
            D1.push_back(G[l]);
          else
            D2.push_back(G[l]);
        }
      break;
    }
    if (st[k].ind >= 0) {
      rcnt += G[st[k].ind].r;
      if (G[st[k].ind].r == 0)
        acnt++;
      else
        bcnt++;
      ch[st[k].ind] = 1;
    } else {
      rcnt -= G[-st[k].ind - 1].r;
      if (G[-st[k].ind - 1].r == 0)
        acnt--;
      else
        bcnt--;
      ch[-st[k].ind - 1] = 0;
    }
  }
  D1.push_back({G[m].x, G[m].y, o, G[m].num});
  D2.push_back({G[m].x, G[m].y, G[m].r - o, G[m].num});
  solve(D1);
  solve(D2);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &a, &b);
    vector<A> P;
    for (i = 0; i < b; i++) {
      scanf("%d", &R[i]);
    }
    for (i = 0; i < a; i++) {
      scanf("%d%d", &X, &Y);
      P.push_back({X, Y, 0, i + 1});
    }
    for (i = 0; i < b; i++) {
      scanf("%d%d", &X, &Y);
      P.push_back({X, Y, R[i], i + 1});
    }
    puts("YES");
    solve(P);
  }
}
