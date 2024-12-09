#include <bits/stdc++.h>
using namespace std;
int ans = INT_MAX;
vector<int> v;
int gao(int a, int b) {
  vector<int> v = ::v;
  int ret = 0;
  bool ok = false;
  for (int i = (((int)(v).size()) - 0) - 1; i >= (0); --i)
    if (v[i] == b) {
      for (int j = (i); j < (((int)(v).size()) - 1); ++j) {
        swap(v[j], v[j + 1]);
        ret++;
      }
      ok = true;
      break;
    }
  if (!ok) return INT_MAX;
  ok = false;
  for (int i = (((int)(v).size()) - 1) - 1; i >= (0); --i)
    if (v[i] == a) {
      for (int j = (i); j < (((int)(v).size()) - 2); ++j) {
        swap(v[j], v[j + 1]);
        ret++;
      }
      ok = true;
      break;
    }
  if (!ok) return INT_MAX;
  if (v[0] == 0) {
    for (int i = (0); i < (((int)(v).size()) - 2); ++i)
      if (v[i] != 0) return ret + i;
    return INT_MAX;
  } else
    return ret;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long n;
  cin >> n;
  while (n) {
    v.push_back(n % 10);
    n /= 10;
  }
  reverse((v).begin(), (v).end());
  int ans = INT_MAX;
  ans = min(ans, gao(0, 0));
  ans = min(ans, gao(2, 5));
  ans = min(ans, gao(5, 0));
  ans = min(ans, gao(7, 5));
  if (ans == INT_MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
