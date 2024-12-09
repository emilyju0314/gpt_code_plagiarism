#include <bits/stdc++.h>
using namespace std;
void adde(vector<long long int> adj[], long long int u, long long int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  long long int ans = 0;
  if (n > m) {
    long long int c = n;
    n = m;
    m = c;
  }
  if (n == 1) {
    long long int temp = 0;
    ans += 6 * long(m / 6) + 2 * max(temp, m % 6 - 3);
  } else if (n == 2) {
    if (m == 2) {
    } else if (m == 3)
      ans += 4;
    else if (m == 7)
      ans += 12;
    else
      ans += n * m;
  } else {
    if ((n * m) % 2 == 0)
      ans += n * m;
    else
      ans += n * m - 1;
  }
  cout << ans << "\n";
  return 0;
}
