#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> nxt(n + 5, 0);
    for (int i = 1; i <= n; i++) {
      cin >> nxt[i];
    }
    vector<bool> used(n + 5, 0);
    vector<int> sol(n + 5, 0);
    for (int i = 1; i <= n; i++) {
      if (used[i] == 0) {
        int node = i;
        vector<int> p;
        while (used[node] == 0) {
          used[node] = 1;
          p.push_back(node);
          node = nxt[node];
        }
        for (int j = 0; j < p.size(); j++) {
          sol[p[j]] = p.size();
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << sol[i] << " ";
    }
    cout << '\n';
  }
}
