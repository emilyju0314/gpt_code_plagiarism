#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  vector< int > g[100000];
  int deg[100000] = {};
  for(int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
    deg[x]++;
    deg[y]++;
  }
  queue< int > que;
  for(int i = 0; i < N; i++) {
    if(deg[i] == 1) {
      que.emplace(i);
    }
  }
  while(que.size()) {
    int idx = que.front();
    que.pop();
    for(auto &to : g[idx]) {
      if(--deg[to] == 1) {
        que.emplace(to);
      }
    }
  }
  int Q;
  cin >> Q;

  while(Q--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if(deg[a] >= 2 && deg[b] >= 2) cout << 2 << endl;
    else cout << 1 << endl;
  }

}
