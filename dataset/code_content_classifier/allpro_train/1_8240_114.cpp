#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mz = 1e9 + 7;
int p[N], t[N][3];
vector<int> G[N];
bool vis[N];
int main() {
  int n, temp;
  cin >> n;
  for (int i = 1; i <= n - 2; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", t[i] + j);
      p[t[i][j]]++;
      G[t[i][j]].push_back(i);
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (p[i] == 1) {
      printf("%d", i);
      temp = 0;
      for (int v : G[i]) {
        for (int j = 0; j < 3; j++) {
          vis[t[v][j]] = true;
          if (t[v][j] == i) {
            continue;
          } else if (p[t[v][j]] == 2) {
            q.push(t[v][j]);
          } else {
            temp = t[v][j];
          }
        }
      }
      q.push(temp);
      break;
    }
  }
  temp = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    printf(" %d", u);
    for (int v : G[u]) {
      for (int j = 0; j < 3; j++) {
        if (vis[t[v][j]]) {
          continue;
        } else if (p[t[v][j]] <= 2) {
          temp = t[v][j];
        } else {
          q.push(t[v][j]);
        }
        vis[t[v][j]] = true;
      }
      if (temp > 0) {
        q.push(temp);
        temp = 0;
      }
    }
  }
  puts("");
  return 0;
}
