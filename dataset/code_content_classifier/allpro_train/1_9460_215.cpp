#include <bits/stdc++.h>
using namespace std;
long long int modpow(long long int a, long long int b,
                     long long int m = 1000000007) {
  a %= m;
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
long long int bpow(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int modinv(long long int a, long long int m = 1000000007) {
  return modpow(a, m - 2, m);
}
void graph(vector<vector<int> > &adj, vector<vector<int> > &adj1, int m) {
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj1[y - 1].push_back(x - 1);
  }
}
bool dfs(int u, vector<vector<int> > &adj, vector<bool> &inStack,
         vector<bool> &visited, vector<int> &minimal) {
  visited[u] = true;
  inStack[u] = true;
  bool isCycle = true;
  for (auto v : adj[u]) {
    if (visited[v] && inStack[v]) return false;
    if (!visited[v])
      isCycle = isCycle && dfs(v, adj, inStack, visited, minimal);
    minimal[u] = min(min(minimal[u], minimal[v]), v);
  }
  inStack[u] = false;
  return isCycle;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n);
  vector<vector<int> > adj1(n);
  graph(adj, adj1, m);
  vector<char> output(n);
  fill(output.begin(), output.end(), 'E');
  ;
  vector<bool> visited(n);
  fill(visited.begin(), visited.end(), false);
  ;
  vector<int> minimal1(n);
  fill(minimal1.begin(), minimal1.end(), INT_MAX);
  ;
  vector<int> minimal2(n);
  fill(minimal2.begin(), minimal2.end(), INT_MAX);
  ;
  vector<bool> inStack(n);
  fill(inStack.begin(), inStack.end(), false);
  ;
  for (int i = 0; i < n; i++)
    if (!visited[i] && !dfs(i, adj, inStack, visited, minimal1)) {
      cout << -1 << '\n';
      return;
    }
  fill(visited.begin(), visited.end(), false);
  ;
  for (int i = 0; i < n; i++)
    if (!visited[i] && !dfs(i, adj1, inStack, visited, minimal2)) {
      cout << -1 << '\n';
      return;
    }
  for (int i = 0; i < n; i++) minimal1[i] = min(minimal1[i], minimal2[i]);
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (minimal1[i] > i) cnt++, output[i] = 'A';
  cout << cnt << '\n';
  for (auto elem : output) cout << elem;
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
}
