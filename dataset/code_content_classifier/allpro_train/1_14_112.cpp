#include <bits/stdc++.h>
using namespace std;
struct Minion {
  int ind;
  long long a, b;
  Minion(int ii = 0, long long ia = 0, long long ib = 0) {
    ind = ii;
    a = ia;
    b = ib;
  }
};
bool cmp(Minion a, Minion b) { return a.b < b.b; }
Minion a[100];
long long dp[100][100];
void solve() {
  int n, k;
  cin >> n >> k;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    ::a[i] = Minion(i, a - k * b, b);
  }
  sort(a + 1, a + n + 1, cmp);
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[0][i] = -1e14;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i].a + j * a[i].b);
    }
    for (int j = i + 1; j <= n; j++) {
      dp[i][j] = -1e14;
    }
  }
  vector<int> ord;
  set<int> st;
  int ind = n, cnt = k;
  while (ind > 0 && cnt > 0) {
    if (dp[ind][cnt] == dp[ind - 1][cnt - 1] + a[ind].a + cnt * a[ind].b) {
      ord.push_back(ind);
      cnt--;
      st.insert(ind);
    }
    ind--;
  }
  reverse(ord.begin(), ord.end());
  vector<int> op;
  for (int i = 0; i + 1 < ord.size(); i++) {
    op.push_back(a[ord[i]].ind);
  }
  for (int i = 1; i <= n; i++) {
    if (st.find(i) == st.end()) {
      op.push_back(a[i].ind);
      op.push_back(-a[i].ind);
    }
  }
  op.push_back(a[ord.back()].ind);
  cout << op.size() << '\n';
  for (auto x : op) {
    cout << x << " ";
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(32);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
