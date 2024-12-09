#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MAXN = (int)2e5 + 10;
const int MOD = (int)1e9 + 7;
int P[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i + 1 <= n; i++) cin >> a[i];
  set<int, greater<int> > have;
  for (int i = 1; i <= n; i++) have.insert(i);
  int cur = a[1];
  have.erase(a[1]);
  for (int i = 2; i + 1 <= n; i++) {
    if (have.count(a[i])) {
      P[a[i]] = cur;
      cur = a[i];
      have.erase(a[i]);
    } else {
      P[*have.begin()] = cur;
      have.erase(have.begin());
      cur = a[i];
    }
  }
  assert(have.size() == 1);
  P[*have.begin()] = cur;
  cout << a[1] << '\n';
  for (int i = 1; i <= n; i++) {
    if (P[i]) {
      cout << P[i] << ' ' << i << '\n';
    }
  }
  return 0;
}
