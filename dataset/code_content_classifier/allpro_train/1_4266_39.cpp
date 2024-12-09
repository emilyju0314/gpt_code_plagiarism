#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
pair<long long, long long> DivideNConq(vector<vector<int> > v, int bit) {
  if (bit < 0) return {0, 0};
  vector<vector<int> > R;
  long long bit_pos0 = 0, bit_pos1 = 0;
  for (auto it : v) {
    vector<int> v0, v1;
    long long ones = 0, zeros = 0;
    for (auto i : it) {
      if ((i >> bit) & 1) {
        ones++;
        bit_pos1 += zeros;
        v1.push_back(i);
      } else {
        zeros++;
        bit_pos0 += ones;
        v0.push_back(i);
      }
    }
    if (v0.size() > 0) R.push_back(v0);
    if (v1.size() > 0) R.push_back(v1);
  }
  auto p = DivideNConq(R, bit - 1);
  int x = (bit_pos1 < bit_pos0);
  return {min(bit_pos0, bit_pos1) + p.first, power(2, bit) * x + p.second};
}
void nikal_pehli_fursat_mai() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  auto ans = DivideNConq({a}, 30);
  cout << ans.first << " " << ans.second << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  while (tc--) {
    nikal_pehli_fursat_mai();
  }
}
