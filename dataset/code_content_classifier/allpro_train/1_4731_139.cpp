#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, ans = 0;
  cin >> n;
  pi a[maxn];
  for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
  sort(a + 1, a + n + 1);
  vector<int> tv1, tv2;
  for (int i = 1; i <= n; ++i) {
    if (tv1.empty() || a[tv1.back()].second < a[i].first) {
      tv1.push_back(i);
      continue;
    }
    if (tv2.empty() || a[tv2.back()].second < a[i].first) tv2.push_back(i);
  }
  if (tv1.size() + tv2.size() == n)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
