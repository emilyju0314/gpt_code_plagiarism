#include <bits/stdc++.h>
using namespace std;
int mark[1005][1005];
int R, C;
int maxSeg[1005];
int visited[1005][1005];
int cx[] = {0, 0, 1, -1}, cy[] = {1, -1, 0, 0};
void dfs(int ii, int jj, int jump) {
  visited[ii][jj] = 1;
  for (int i = 0; i < 4; i++) {
    int cnt = 0;
    for (int j = 1; j <= jump; j++) {
      int iii = ii + cx[i] * j;
      int jjj = jj + cy[i] * j;
      if (iii >= 0 && jjj >= 0 && iii < R && jjj < C && mark[iii][jjj]) {
        cnt++;
      }
    }
    if (cnt == jump) {
      for (int j = 1; j < jump; j++) {
        int iii = ii + cx[i] * j;
        int jjj = jj + cy[i] * j;
        visited[iii][jjj] = 2;
      }
      if (visited[ii + cx[i] * jump][jj + cy[i] * jump] != 1) {
        dfs(ii + cx[i] * jump, jj + cy[i] * jump, jump);
      }
    }
  }
}
int numDegree[1005 * 1005];
bool check(int jump) {
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) visited[i][j] = 0;
  int cc = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (!visited[i][j] && mark[i][j]) {
        cc++;
        if (cc == 2) return false;
        dfs(i, j, jump);
      }
    }
  }
  int n_vertex = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (visited[i][j] == 1) {
        n_vertex++;
        visited[i][j] = -n_vertex;
      }
    }
  }
  fill(numDegree, numDegree + n_vertex + 1, 0);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (visited[i][j] < 0) {
        for (int k = 0; k < 4; k++) {
          int ii = i + cx[k] * jump;
          int jj = j + cy[k] * jump;
          if (ii >= 0 && jj >= 0 && ii < R && jj < C && visited[ii][jj] < 0 &&
              mark[i + cx[k]][j + cy[k]]) {
            numDegree[-visited[i][j]]++;
          }
        }
      }
    }
  }
  int numOdd = 0;
  for (int i = 1; i <= n_vertex; i++) {
    if (numDegree[i] % 2) numOdd++;
  }
  return numOdd == 0 || numOdd == 2;
}
int main() {
  scanf("%d %d", &R, &C);
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) scanf("%d", &mark[i][j]);
  int maxx = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (mark[i][j]) {
        if (!j)
          maxSeg[j] = 1;
        else
          maxSeg[j] = maxSeg[j - 1] + 1;
      } else {
        maxSeg[j] = 0;
      }
      maxx = max(maxx, maxSeg[j]);
    }
  }
  for (int j = 0; j < C; j++) {
    for (int i = 0; i < R; i++) {
      if (mark[i][j]) {
        if (!i)
          maxSeg[i] = 1;
        else
          maxSeg[i] = maxSeg[i - 1] + 1;
      } else {
        maxSeg[i] = 0;
      }
      maxx = max(maxx, maxSeg[i]);
    }
  }
  maxx--;
  vector<int> ans;
  for (int i = 2; i <= maxx; i++) {
    if (maxx % i == 0 && check(i)) {
      ans.push_back(i);
    }
  }
  if (ans.size() == 0)
    printf("-1\n");
  else {
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
    printf("\n");
  }
  return 0;
}
