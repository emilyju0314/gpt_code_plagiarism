#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30010;
int N, M;
set<int> adj[MAXN];
vector<int> ans;
bool owe(int a, int b) { return adj[a].count(b); }
int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].insert(b);
  }
  for (int i = 1; i <= N; i++) {
    ans.push_back(i);
    for (int j = ans.size() - 2; j >= 0; j--) {
      if (owe(ans[j], i)) {
        swap(ans[j], ans[j + 1]);
      } else {
        break;
      }
    }
  }
  for (int i = 0; i < N - 1; i++) {
    if (owe(ans[i], ans[i + 1])) {
      cout << "-1\n";
      return 0;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << ' ';
  }
}
