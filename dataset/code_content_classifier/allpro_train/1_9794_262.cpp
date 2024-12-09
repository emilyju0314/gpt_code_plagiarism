#include <bits/stdc++.h>
using namespace std;
const long long int lim = 2e5 + 1;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long int m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
vector<long long int> farArr;
long long int parent[lim], visited[lim], far[lim];
void dfs(long long int n1, long long int p, long long int d, long long int n,
         long long int parent[], long long int visited[], long long int far[],
         vector<long long int> a[]) {
  visited[n1] = 1;
  parent[n1] = p;
  for (int i = 0; i < a[n1].size(); i++) {
    if (!visited[a[n1][i]]) {
      dfs(a[n1][i], n1, d + 1, n, parent, visited, far, a);
    }
  }
  if (d > 2) {
    farArr.push_back(n1);
    far[n1] = 1;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, ans = 0;
  cin >> n;
  vector<long long int> a[200001];
  for (int i = 1; i < n; i++) {
    parent[i] = -1;
    visited[i] = 0;
    far[i] = 0;
    long long int n1, n2;
    cin >> n1 >> n2;
    a[n1].push_back(n2);
    a[n2].push_back(n1);
  }
  parent[n] = -1;
  visited[n] = 0;
  far[n] = 0;
  dfs(1, -1, 0, n, parent, visited, far, a);
  for (int i = 0; i < farArr.size(); i++) {
    long long int n1 = farArr[i];
    if (far[n1]) {
      long long int p = parent[n1];
      far[p] = 0;
      ans += 1;
      for (int j = 0; j < a[p].size(); j++) {
        long long int n2 = a[p][j];
        if (far[n2]) {
          far[n2] = 0;
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
