#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.first > b.first);
}
string getString(char x) {
  string s(1, x);
  return s;
}
long long max(long long a, long long b) {
  if (b > a)
    return b;
  else {
    return a;
  }
}
long long power(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long factorial[500005];
void swap(int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
int visited[200005], val[200000];
void DFS(long long n, vector<int> v[]) {
  visited[n] = 1;
  for (int i = 0; i < v[n].size(); i++) {
    if (visited[v[n][i]] == 0) {
      DFS(v[n][i], v);
    }
  }
}
void dfs(int n, vector<int> v[], int dis) {
  visited[n] = 1;
  val[n] = dis;
  for (int i = 0; i < v[n].size(); i++) {
    if (visited[v[n][i]] == 0) {
      dfs(v[n][i], v, dis + 1);
    }
  }
}
int vitree(int n, vector<int> v[]) {
  int count = 0;
  visited[n] = 1;
  for (int i = 0; i < v[n].size(); i++) {
    if (visited[v[n][i]] == 0) {
      count += vitree(v[n][i], v);
    }
  }
  if (count == 0) {
    val[n] = 1;
    return 1;
  } else {
    val[n] = count;
    return count;
  }
}
bool bipartite(int n, vector<int> v[], int co) {
  visited[n] = 1;
  val[n] = co;
  for (int i = 0; i < v[n].size(); i++) {
    if (visited[v[n][i]] == 0) {
      bool m = bipartite(v[n][i], v, (co == 1) ? 0 : 1);
      if (m == false) return false;
    } else {
      if (val[v[n][i]] == co) return false;
    }
  }
  return true;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int dp[202][202][202];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, g, b;
  cin >> r >> g >> b;
  int x[r], y[g], z[b];
  for (int i = 0; i < r; i++) cin >> x[i];
  for (int i = 0; i < g; i++) cin >> y[i];
  for (int i = 0; i < b; i++) cin >> z[i];
  int ans = 0;
  sort(x, x + r, greater<int>());
  sort(y, y + g, greater<int>());
  sort(z, z + b, greater<int>());
  for (int i = 0; i < r + 1; i++) {
    for (int j = 0; j < g + 1; j++) {
      for (int k = 0; k < b + 1; k++) {
        if (i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
        if (j) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
        if (k) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
        if (i && j)
          dp[i][j][k] =
              max(dp[i][j][k], dp[i - 1][j - 1][k] + x[i - 1] * y[j - 1]);
        if (j && k)
          dp[i][j][k] =
              max(dp[i][j][k], dp[i][j - 1][k - 1] + z[k - 1] * y[j - 1]);
        if (i && k)
          dp[i][j][k] =
              max(dp[i][j][k], dp[i - 1][j][k - 1] + x[i - 1] * z[k - 1]);
        ans = max(ans, dp[i][j][k]);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
