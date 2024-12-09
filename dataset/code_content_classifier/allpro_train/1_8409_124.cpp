#include <bits/stdc++.h>
using namespace std;
int level[100001];
int main() {
  int n, m;
  cin >> n >> m;
  set<int> store;
  memset(level, 0, sizeof(level));
  for (int i = 0; i < m; i++) {
    int d;
    cin >> d;
    level[d]++;
    store.insert(d);
    if (store.size() == n) {
      cout << 1;
      store.clear();
      for (int j = 1; j <= n; j++) {
        level[j]--;
        if (level[j] > 0) store.insert(j);
      }
    } else
      cout << 0;
  }
  cout << endl;
  return 0;
}
