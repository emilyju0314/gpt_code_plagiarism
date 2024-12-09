#include <bits/stdc++.h>
using namespace std;
int co2[1000001], vis[3001];
bool has[1001];
int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int t;
    cin >> t;
    has[t] = true;
  }
  k = 0;
  for (int i = 0; i <= 1000; i++) {
    if (has[i]) co2[k++] = i - n;
  }
  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int i = 0; i < k; i++) {
      int nxt = cur.first + co2[i];
      if (nxt == 0) {
        cout << cur.second + 1 << '\n';
        return 0;
      } else if (-1000 <= nxt && nxt <= 1000 && !vis[nxt + 1000]) {
        vis[nxt + 1000] = true;
        q.push(make_pair(nxt, cur.second + 1));
      }
    }
  }
  cout << "-1\n";
}
