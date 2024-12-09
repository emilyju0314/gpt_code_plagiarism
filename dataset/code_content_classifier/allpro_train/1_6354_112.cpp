#include <bits/stdc++.h>
using namespace std;
inline void OPEN(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
char s[2020], board[2020][2020];
int n, m, visited[2020][2020], realans, d[2020][2020];
vector<pair<int, int> > adj[2020][2020];
vector<int> ans;
queue<pair<int, int> > q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); ++i) {
    scanf("%s", s);
    for (int j = (1); j <= (m); ++j) board[i][j] = s[j - 1];
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      if (board[i][j - 1] == '>') adj[i][j].push_back(make_pair(i, j - 1));
      if (board[i][j + 1] == '<') adj[i][j].push_back(make_pair(i, j + 1));
      if (board[i - 1][j] == 'v') adj[i][j].push_back(make_pair(i - 1, j));
      if (board[i + 1][j] == '^') adj[i][j].push_back(make_pair(i + 1, j));
    }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      if (visited[i][j]) continue;
      if (board[i][j] != '#') continue;
      visited[i][j] = 1;
      for (__typeof((adj[i][j]).begin()) x = (adj[i][j]).begin();
           x != (adj[i][j]).end(); x++) {
        while (!q.empty()) q.pop();
        q.push(make_pair(x->first, x->second));
        d[x->first][x->second] = 0;
        int last = 0;
        while (!q.empty()) {
          pair<int, int> now = q.front();
          q.pop();
          visited[now.first][now.second] = 1;
          last = d[now.first][now.second];
          for (__typeof((adj[now.first][now.second]).begin()) it =
                   (adj[now.first][now.second]).begin();
               it != (adj[now.first][now.second]).end(); it++) {
            if (visited[it->first][it->second]) {
              puts("-1");
              return 0;
            }
            q.push(make_pair(it->first, it->second));
            d[it->first][it->second] = last + 1;
          }
        }
        ans.push_back(last + 1);
      }
    }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      if (!visited[i][j]) {
        puts("-1");
        return 0;
      }
    }
  sort((ans).begin(), (ans).end());
  reverse((ans).begin(), (ans).end());
  if (((int)(ans).size()) == 0) {
    realans = 0;
  } else if (((int)(ans).size()) == 1) {
    realans = max(0, ans[0] + ans[0] - 1);
  } else {
    realans = ans[0] + max(ans[0] - 1, ans[1]);
  }
  printf("%d\n", realans);
  return 0;
}
