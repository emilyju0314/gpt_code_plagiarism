#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int> > adjlist;
int A[200005][25], L[200005];
void dfs(int i, int l) {
  L[i] = l;
  for (int j = 0; j < (int)adjlist[i].size(); j++) dfs(adjlist[i][j], l + 1);
}
void precompute() {
  for (int j = 1; j <= 20; j++)
    for (int i = 0; i < N; i++)
      if (A[i][j - 1] != -1)
        A[i][j] = A[A[i][j - 1]][j - 1];
      else
        A[i][j] = -1;
  dfs(0, 0);
}
int lca(int p, int q) {
  if (L[p] < L[q]) swap(p, q);
  for (int i = 20; i >= 0; i--)
    if (L[p] - (1 << i) >= L[q]) p = A[p][i];
  if (p == q) return p;
  for (int i = 20; i >= 0; i--)
    if (A[p][i] != -1 && A[p][i] != A[q][i]) {
      p = A[p][i];
      q = A[q][i];
    }
  return A[p][0];
}
int main() {
  scanf("%d", &N);
  adjlist.assign(N, vector<int>());
  A[0][0] = -1;
  for (int i = 1; i < N; i++) {
    int x;
    scanf("%d", &x);
    adjlist[x - 1].push_back(i);
    A[i][0] = x - 1;
  }
  precompute();
  int ki = 0, ka = 0, diameter = 0;
  for (int i = 1; i < N; i++) {
    int tmp = L[ki] + L[i] - 2 * L[lca(ki, i)];
    if (tmp > diameter) {
      ka = i;
      diameter = tmp;
    }
    tmp = L[ka] + L[i] - 2 * L[lca(ka, i)];
    if (tmp > diameter) {
      ki = i;
      diameter = tmp;
    }
    printf("%d ", diameter);
  }
  puts("");
  return 0;
}
