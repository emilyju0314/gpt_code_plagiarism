#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
vector<vector<long long> > adj;
vector<bool> visited;
void dfs(long long v) {
  visited[v] = true;
  for (long long u : adj[v]) {
    if (!visited[u]) dfs(u);
  }
}
int main() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v(n);
  vector<long long> a(n);
  long long x;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    a[i] = (x >= 0 ? -x - 1 : x);
    v[i] = {x, i};
  }
  sort(a.begin(), a.end());
  if (n % 2 == 0) {
    for (long long i = 0; i < n; i++) {
      if (v[i].first >= 0) v[i].first = -v[i].first - 1;
    }
    for (long long i = 0; i < n; i++) {
      cout << v[i].first << " ";
    }
    cout << endl;
  } else {
    long long c = 0;
    long long pos = 0;
    for (long long i = 0; i < n; i++) {
      if (v[i].first >= 0) {
        v[i].first = -v[i].first - 1;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (v[i].first != -1 && v[i].first < v[pos].first) {
        pos = i;
      }
    }
    v[pos].first = -v[pos].first - 1;
    for (long long i = 0; i < n; i++) cout << v[i].first << " ";
    cout << endl;
  }
  return 0;
}
