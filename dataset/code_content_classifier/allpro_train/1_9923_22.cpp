#include <bits/stdc++.h>
using namespace std;
const int M = 1 << 13;
const int N = 13;
long long dp[M][N][2][2];
bool used[M][N][2][2];
vector<int> digits_hour, digits_minuts;
long long solve(int mask, int pos, bool flag1, bool flag2) {
  int h = digits_hour.size();
  int min = digits_minuts.size();
  if (pos == h + min) {
    return 1LL;
  }
  long long &ans = dp[mask][pos][flag1][flag2];
  if (used[mask][pos][flag1][flag2]) {
    return ans;
  }
  used[mask][pos][flag1][flag2] = true;
  if (pos >= h) {
    for (int t = 0; t < 7; t++) {
      int el = 1 << t;
      if ((mask & el) == 0) {
        if (flag2 || digits_minuts[pos - h] >= t) {
          ans += solve(mask | el, pos + 1, flag1,
                       flag2 || (digits_minuts[pos - h] > t));
        }
      }
    }
  } else {
    for (int t = 0; t < 7; t++) {
      int el = 1 << t;
      if ((mask & el) == 0) {
        if (flag1 || digits_hour[pos] >= t) {
          ans +=
              solve(mask | el, pos + 1, flag1 || (digits_hour[pos] > t), flag2);
        }
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  scanf("%d %d", &n, &m);
  n--, m--;
  if (n == 0) {
    digits_hour.push_back(0);
  }
  if (m == 0) {
    digits_minuts.push_back(0);
  }
  while (n) {
    digits_hour.push_back(n % 7);
    n /= 7;
  }
  reverse(digits_hour.begin(), digits_hour.end());
  while (m) {
    digits_minuts.push_back(m % 7);
    m /= 7;
  }
  reverse(digits_minuts.begin(), digits_minuts.end());
  printf("%lld\n", solve(0, 0, false, false));
  return 0;
}
