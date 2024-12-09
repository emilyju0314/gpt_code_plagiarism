#include <bits/stdc++.h>
using namespace std;
long long n;
vector<int> adj[200005];
bool isprime(long long x) {
  for (int i = 2; i <= sqrt(x); i++)
    if (x % i == 0) return 0;
  return 1;
}
void solve() {
  map<std::pair<int, int>, int> check;
  for (int i = n - 1; i >= 2; i--) {
    if (!isprime(i)) continue;
    for (int j = n - 1; j >= 1; j--) {
      if (!isprime(i + j)) continue;
      if (j + (n - 1 == i ? 0 : n - i) < n / 2) continue;
      for (long long k = 1; k < (i + 1); ++k) {
        adj[n].push_back(k);
        check[{n, k}] = 1;
        check[{k, n}] = 1;
      }
      int cnt = n - 1 - j;
      if (i != n - 1)
        for (long long k = i + 1; k < (n); ++k) {
          if (adj[k].size() == 0) {
            if (!check[{k, k - 1}] && !check[{k - 1, k}]) {
              adj[k].push_back(k - 1);
              check[{k, k - 1}] = 1;
              check[{k - 1, k}] = 1;
            }
            if (k == n - 1 && !check[{k, 1}] && !check[{k, 1}]) {
              adj[k].push_back(1);
              check[{k, 1}] = 1;
              check[{1, k}] = 1;
            }
          }
        }
      for (long long k = 1; k < (i + 1); ++k) {
        if (k % 2 == 1 && cnt)
          cnt--;
        else {
          if (k == n - 1 && !check[{k, 1}] && !check[{k, 1}]) {
            adj[k].push_back(1);
            check[{k, 1}] = 1;
            check[{1, k}] = 1;
          } else if (!check[{k, k + 1}] && !check[{k + 1, k}]) {
            adj[k].push_back(k + 1);
            check[{k, k + 1}] = 1;
            check[{k + 1, k}] = 1;
          }
        }
      }
      int ans = 0;
      for (long long k = 1; k < (n + 1); ++k) {
        if (adj[k].size())
          for (auto l : adj[k]) ans++;
      }
      cout << ans << "\n";
      for (long long k = 1; k < (n + 1); ++k) {
        if (adj[k].size())
          for (auto l : adj[k]) cout << k << ' ' << l << "\n";
      }
      return;
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  while (test--) {
    cin >> n;
    solve();
  }
}
