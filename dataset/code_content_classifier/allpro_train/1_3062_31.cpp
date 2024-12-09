#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e2 + 5;
const int INF = 2e9;
const int MOD = 1e9 + 7;
int edge = 0, A[MAXN], B[MAXN];
vector<int> graph[MAXN], comp, path;
bool used[MAXN], suse[MAXN];
vector<pair<pair<int, int>, int> > RES;
void dfs(int v, long long &addTo) {
  addTo += A[v] - B[v];
  used[v] = true;
  for (int i = 0; i < graph[v].size(); i++) {
    int to = graph[v][i];
    if (!used[to]) dfs(to, addTo);
  }
  comp.push_back(v);
}
bool get_path(int v, int aim) {
  suse[v] = true;
  if (v == aim) {
    path.push_back(aim);
    return true;
  }
  for (int i = 0; i < graph[v].size(); i++) {
    int to = graph[v][i];
    if (!suse[to] && get_path(to, aim)) {
      path.push_back(v);
      return true;
    }
  }
  return false;
}
void bring(int pos, int amount) {
  if (pos == 0) return;
  int v = path[pos], to = path[pos - 1];
  int curI = min(amount, A[to]);
  if (curI) {
    A[to] -= curI, A[v] += curI;
    RES.push_back(make_pair(make_pair(to, v), curI));
  }
  bring(pos - 1, amount);
  curI = amount - curI;
  if (curI) {
    A[to] -= curI, A[v] += curI;
    RES.push_back(make_pair(make_pair(to, v), curI));
  }
}
int main() {
  int N = 0, M = 0;
  long long ANSWEREXISTS = 0;
  scanf("%i%i%i", &N, &edge, &M);
  for (int i = 1; i <= N; i++) scanf("%i", &A[i]);
  for (int i = 1; i <= N; i++) scanf("%i", &B[i]);
  for (int i = 1, L = 0, R = 0; i <= M; i++) {
    scanf("%i%i", &L, &R);
    graph[L].push_back(R);
    graph[R].push_back(L);
  }
  for (int i = 1; i <= N; i++)
    if (!used[i]) {
      ANSWEREXISTS = 0;
      dfs(i, ANSWEREXISTS);
      if (ANSWEREXISTS) return printf("NO\n"), 0;
      for (int ii = 0; ii < comp.size(); ii++)
        if (A[comp[ii]] != B[comp[ii]])
          for (int jj = 0; jj < comp.size(); jj++) {
            if (ii == jj || A[comp[jj]] == B[comp[jj]]) continue;
            int BEG = 0, END = 0, AMOUNT = 0;
            if (A[comp[ii]] < B[comp[ii]] && A[comp[jj]] > B[comp[jj]])
              BEG = comp[jj], END = comp[ii],
              AMOUNT =
                  min(B[comp[ii]] - A[comp[ii]], A[comp[jj]] - B[comp[jj]]);
            else if (A[comp[ii]] > B[comp[ii]] && A[comp[jj]] < B[comp[jj]])
              BEG = comp[ii], END = comp[jj],
              AMOUNT =
                  min(A[comp[ii]] - B[comp[ii]], B[comp[jj]] - A[comp[jj]]);
            if (BEG == 0 && END == 0) continue;
            memset(suse, false, sizeof(suse));
            path.clear();
            get_path(BEG, END);
            reverse(path.begin(), path.end());
            bring(path.size() - 1, AMOUNT);
          }
      comp.clear();
    }
  printf("%i\n", RES.size());
  for (int i = 0; i < RES.size(); i++)
    printf("%i %i %i\n", RES[i].first.first, RES[i].first.second,
           RES[i].second);
  return 0;
}
