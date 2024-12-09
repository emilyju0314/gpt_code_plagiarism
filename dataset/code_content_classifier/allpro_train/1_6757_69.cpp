#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int A[N][N];
pair<int, int> P[N * N + 1];
pair<int, int> B[N][N][3];
pair<int, int> S[N * N + 1][3];
vector<pair<int, int>> M[3];
int n;
void dfs(int cr, int cc, int type) {
  queue<vector<int>> q;
  q.push({cr, cc, type, 0, 0});
  while (!q.empty()) {
    vector<int> &node = q.front();
    cr = node[0], cc = node[1], type = node[2];
    q.pop();
    int ts = B[cr][cc][type].first;
    int tr = B[cr][cc][type].second;
    if (ts != node[3] || tr != node[4]) continue;
    for (int i = 0; i < 3; i += 1) {
      if (ts + 1 < B[cr][cc][i].first ||
          ts + 1 == B[cr][cc][i].first && tr + 1 < B[cr][cc][i].second) {
        B[cr][cc][i] = {ts + 1, tr + 1};
        q.push({cr, cc, i, ts + 1, tr + 1});
      }
    }
    for (auto pr : M[type]) {
      for (int j = 1; j < n; j += 1) {
        int nr = cr + pr.first * j;
        int nc = cc + pr.second * j;
        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
          int ts = B[cr][cc][type].first + 1;
          int tr = B[cr][cc][type].second;
          if (ts < B[nr][nc][type].first ||
              ts == B[nr][nc][type].first && tr < B[nr][nc][type].second) {
            B[nr][nc][type] = {ts, tr};
            q.push({nr, nc, type, ts, tr});
          }
        } else
          break;
        if (type == 0) break;
      }
    }
  }
}
void solve(int cr, int cc) {
  if (A[cr][cc] == n * n) {
    S[n * n][0] = S[n * n][1] = S[n * n][2] = {0, 0};
    return;
  }
  int cn = A[cr][cc];
  int nr = P[cn + 1].first;
  int nc = P[cn + 1].second;
  solve(nr, nc);
  for (int i = 0; i < 3; i += 1) {
    for (int r = 0; r < n; r += 1)
      for (int c = 0; c < n; c += 1)
        for (int t = 0; t < 3; t += 1) B[r][c][t] = {1e9, 1e9};
    B[cr][cc][i] = {0, 0};
    dfs(cr, cc, i);
    S[cn][i] = {1e9, 1e9};
    for (int j = 0; j < 3; j += 1) {
      int ts = B[nr][nc][j].first + S[cn + 1][j].first;
      int tr = B[nr][nc][j].second + S[cn + 1][j].second;
      if (ts < S[cn][i].first || ts == S[cn][i].first && tr < S[cn][i].second)
        S[cn][i] = {ts, tr};
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      cin >> A[i][j];
      P[A[i][j]] = {i, j};
    }
  }
  M[0] = {{1, 2},  {1, -2},  {2, 1},   {2, -1},
          {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}};
  M[1] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
  M[2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  solve(P[1].first, P[1].second);
  int cs = S[1][0].first;
  int cr = S[1][0].second;
  for (int i = 0; i < 3; i += 1) {
    if (S[1][i].first < cs || S[1][i].first == cs && S[1][i].second < cr)
      cs = S[1][i].first, cr = S[1][i].second;
  }
  cout << cs << " " << cr << endl;
}
