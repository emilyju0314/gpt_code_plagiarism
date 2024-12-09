#include <bits/stdc++.h>
using namespace std;
vector<char> comp[101];
vector<char> g[27];
int visit[27];
void dfs(char x, int id) {
  visit[x - 48 - '0'] = 1;
  comp[id].push_back(x);
  for (int i = 0; i < g[x - 48 - '0'].size(); i++) {
    if (!visit[g[x - 48 - '0'][i] - 48 - '0']) dfs(g[x - 48 - '0'][i], id);
  }
}
int main() {
  int n;
  int pre[27];
  char s[101][27];
  for (int i = 1; i < 27; i++) pre[i] = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < strlen(s[i]) - 1; j++) {
      g[s[i][j] - 48 - '0'].push_back(s[i][j + 1]);
      pre[s[i][j + 1] - 48 - '0'] = 1;
    }
  }
  int id = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < strlen(s[i]); j++) {
      if (pre[s[i][j] - 48 - '0'] == -1 && !visit[s[i][j] - 48 - '0']) {
        dfs(s[i][j], id);
        id++;
      }
    }
  }
  for (int i = 1; i < id; i++) {
    for (int j = 0; j < comp[i].size(); j++) {
      printf("%c", comp[i][j]);
    }
  }
}
