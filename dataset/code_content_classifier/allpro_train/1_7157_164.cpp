#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int qq = 1e6 + 10;
const int INF = 1e9 + 10;
long long k, m;
long long getNum(long long x) {
  string ans = "";
  while (x > 0) {
    ans += (x % 10 + '0');
    x /= 10;
  }
  string cns = ans;
  reverse(ans.begin(), ans.end());
  ans += cns;
  long long tmp = 0;
  for (int i = 0; i < ans.size(); ++i) {
    tmp = (tmp * 10LL) + ans[i] - '0';
  }
  return tmp;
}
int main() {
  scanf("%lld%lld", &k, &m);
  long long ans = 0;
  for (int i = 1; i <= k; ++i) {
    ans = (ans + getNum(i)) % m;
  }
  printf("%lld\n", ans);
  return 0;
}
