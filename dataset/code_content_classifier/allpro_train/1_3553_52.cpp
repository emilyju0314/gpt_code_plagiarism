#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> G[110];
bool visited[110];
int visitededge;
void dfs(int x) {
  if (visited[x]) return;
  visitededge++;
  visited[x] = true;
  for (int i = 0; i < G[x].size(); i++) {
    dfs(G[x][i]);
  }
}
int main() {
  cin >> n >> m;
  if (n != m) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1);
  if (visitededge < n)
    cout << "NO";
  else
    cout << "FHTAGN!";
  return 0;
}
