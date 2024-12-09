#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;
vector<int> edges[N];
int p[N];
void dfs(int cur, int &timer) {
  p[cur] = timer--;
  for (auto it : edges[cur]) {
    dfs(it, timer);
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> nxt;
  for (int i = 0; i <= n; i++) {
    edges[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    x--;
    if (x == -2) x = i + 1;
    nxt.push_back(x);
    edges[x].push_back(i);
  }
  int timer = n + 1;
  dfs(n, timer);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && p[st.top()] < p[i]) {
      st.pop();
    }
    if ((st.empty() && nxt[i] != n) || (!st.empty() && st.top() != nxt[i])) {
      cout << -1 << endl;
      return;
    }
    st.push(i);
  }
  for (int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
