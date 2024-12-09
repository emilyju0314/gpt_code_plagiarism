#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vpi = vector<pair<int, int>>;
const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < (n); i++) cin >> a[i];
    set<int> uni;
    for (int i = 0; i < (n); i++) uni.insert(a[i]);
    if (uni.size() > k) {
      cout << "-1\n";
      continue;
    }
    vi u;
    for (int x : uni) u.push_back(x);
    while ((int)u.size() < k) u.push_back(a[0]);
    vi b;
    int i = 0, j = 0;
    while (i < n) {
      if (a[i] == u[j]) {
        b.push_back(a[i]);
        i++;
      } else {
        b.push_back(u[j]);
      }
      j = (j + 1) % k;
    }
    cout << (int)b.size() << endl;
    for (int i = 0; i < ((int)b.size()); i++) cout << b[i] << " ";
    cout << endl;
  }
  return 0;
}
