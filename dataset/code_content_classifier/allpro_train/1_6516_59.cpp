#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
const int mod = 1e9 + 7;
void solve() {
  int k;
  cin >> k;
  vector<int> v(12);
  for (int i = 0; i < 12; i++) cin >> v[i];
  if (k == 0) {
    cout << 0;
    return;
  }
  sort(v.begin(), v.end(), greater<int>());
  int sum = 0, res = 0;
  for (int i = 0; i < 12; i++) {
    sum += v[i];
    res++;
    if (sum >= k) break;
  }
  cout << (res == 0 || sum < k ? -1 : res);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
