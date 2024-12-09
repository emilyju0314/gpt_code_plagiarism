#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int main() {
  int w, l;
  cin >> w >> l;
  int a[w];
  vector<int> flow(w, 0);
  a[0] = INF;
  flow[0] = INF;
  for (int i = 1; i <= w - 1; i++) {
    cin >> a[i];
  }
  for (int i = 0; i + l <= w - 1; i++) {
    for (int j = i + l; j >= i + 1 && flow[i] > 0; j--) {
      if (flow[j] < a[j]) {
        int x = a[j] - flow[j], y = min(flow[i], x);
        flow[j] += y;
        flow[i] -= y;
      }
    }
  }
  int ans = 0;
  for (int i = w - l; i <= w - 1; i++) {
    ans += flow[i];
  }
  cout << ans;
}
