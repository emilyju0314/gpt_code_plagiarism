#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long n, a, b;
pair<long long, long long> ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a >> b;
  ans = {INF, INF};
  n *= 6;
  if (n > a * b) {
    for (long long i = min(a, b); i * i <= n; i++) {
      ;
      if (((n + i - 1) / i) * i - n < ans.first * ans.second - n &&
          (n + i - 1) / i > max(a, b)) {
        ans.first = i;
        ans.second = (n + i - 1) / i;
      }
    }
    if (ans.first < a) {
      swap(ans.first, ans.second);
    }
  } else {
    ans = {a, b};
  }
  cout << ans.first * ans.second << '\n';
  cout << ans.first << " " << ans.second << '\n';
  return 0;
}
