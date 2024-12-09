#include <bits/stdc++.h>
using namespace std;
vector<int> vec[200005];
struct node {
  int u, v, k;
  node(int uu, int vv, int kk) { u = uu, v = vv, k = kk; }
  bool operator<(const node& A) const {
    if (u == A.u) return v < A.v;
    return u < A.u;
  }
};
set<node> st;
int ans[200005];
int main() {
  int n;
  cin >> n;
  memset(ans, -1, sizeof(ans));
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
    st.insert(node(u, v, i));
  }
  bool wa = false;
  for (int i = 1; i <= n; i++) {
    if (vec[i].size() >= 3) {
      wa = true;
      for (int j = 0; j < 3; j++) {
        auto it = st.find(node(vec[i][j], i, 1));
        if (it != st.end()) {
          ans[it->k] = j;
        } else {
          it = st.find(node(i, vec[i][j], 1));
          ans[it->k] = j;
        }
      }
      break;
    }
  }
  int tmp = wa ? 3 : 0;
  for (int i = 1; i <= n - 1; i++) {
    if (ans[i] == -1) {
      ans[i] = tmp++;
    }
  }
  for (int i = 1; i <= n - 1; i++) cout << ans[i] << endl;
  return 0;
}
