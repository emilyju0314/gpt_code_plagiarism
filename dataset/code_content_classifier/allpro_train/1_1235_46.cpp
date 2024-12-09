#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long long MOD = 1000000007;
const long long NO_OPERTATION = -1;
long long solve(vector<long long>& v, int x) {
  if (x < 0) {
    return 0;
  }
  vector<long long> ones;
  vector<long long> zeros;
  for (int i = 0; i < v.size(); i++) {
    if ((v[i] & (1 << x)) == 0) {
      zeros.push_back(v[i]);
    } else {
      ones.push_back(v[i]);
    }
  }
  if (ones.size() == 0) {
    return solve(zeros, x - 1);
  }
  if (zeros.size() == 0) {
    return solve(ones, x - 1);
  }
  return min(solve(ones, x - 1), solve(zeros, (x - 1))) + (1 << x);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (auto& qw : (v)) cin >> qw;
  ;
  cout << solve(v, 30) << "\n";
  ;
  return 0;
}
