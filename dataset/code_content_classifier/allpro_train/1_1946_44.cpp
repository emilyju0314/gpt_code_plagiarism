#include <bits/stdc++.h>
using namespace std;
int grl[1000007], grr[1000007], deg[1000007], L[1000007], R[1000007],
    RR[1000007], n;
vector<int> ans;
int leaf = 2;
bool q = true;
void dfs(int v, int mx, bool pp) {
  if (leaf <= mx) {
    if (pp)
      grl[v] = leaf++;
    else
      grr[v] = leaf++;
    v = leaf - 1;
  }
  if (L[v]) dfs(v, L[v], true);
  if (v < n && (RR[v] < leaf || L[v] >= RR[v])) q = false;
  if (R[v] >= leaf || leaf <= mx) dfs(v, max(mx, R[v]), false);
  return;
}
void dfs1(int v) {
  if (!grl[v] && !grr[v]) {
    ans.push_back(v);
    return;
  }
  if (grl[v]) dfs1(grl[v]);
  ans.push_back(v);
  if (grr[v]) dfs1(grr[v]);
}
char s[107];
int main() {
  ios_base::sync_with_stdio(false);
  int c;
  scanf("%d %d", &n, &c);
  if (n == 1 && c >= 1) {
    printf("IMPOSSIBLE");
    return 0;
  }
  for (int i = 1; i <= n; i++) RR[i] = 1000007;
  int a, b, lc = 0, rc = 0, lmax = 0, rmin = 1000007;
  for (int i = 1; i <= c; i++) {
    scanf("%d %d %s", &a, &b, &s);
    if (a >= b) {
      printf("IMPOSSIBLE");
      return 0;
    }
    if (s[0] == 'L')
      L[a] = max(L[a], b);
    else
      R[a] = max(R[a], b), RR[a] = min(RR[a], b);
  }
  R[1] = max(R[1], n + 2);
  dfs(1, 1, true);
  if (!q) {
    printf("IMPOSSIBLE");
    return 0;
  }
  leaf--;
  while (leaf < n) {
    int t = leaf + 1;
    grl[leaf] = t;
    leaf++;
  }
  dfs1(1);
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
