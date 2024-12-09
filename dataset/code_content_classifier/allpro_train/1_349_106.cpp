#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 0;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> adj(3 * n + 1);
    for (long long i = (1); i <= (m); i++) {
      long long a, b;
      cin >> a >> b;
      adj[a].push_back({b, i});
      adj[b].push_back({a, i});
    }
    unordered_map<long long, long long> check;
    vector<long long> matching;
    for (long long i = (1); i <= (3 * n); i++) {
      if (check[i] == 0) {
        for (auto child : adj[i]) {
          if (check[child.first] == 0) {
            matching.push_back(child.second);
            check[i] = 1;
            check[child.first] = 1;
            break;
          }
        }
      }
    }
    if (matching.size() >= n) {
      cout << "Matching"
           << "\n";
      long long ctr = 0;
      for (auto itr = (matching).begin(); itr != (matching).end(); itr++) {
        cout << *itr << " ";
        ctr++;
        if (ctr == n) break;
      }
      cout << "\n";
    } else {
      cout << "IndSet"
           << "\n";
      long long ctr = 0;
      for (long long i = (1); i <= (3 * n); i++) {
        if (check[i] == 0) {
          cout << i << " ";
          ctr++;
        }
        if (ctr == n) break;
      }
      cout << "\n";
    }
  }
  return 0;
}
