#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)5e5 + 5;
int arr[MAXN];
int n;
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
  int zero = 0, two = -1;
  set<pair<long long, long long> > one;
  long long shifter = 0;
  int sign = 1;
  for (int i = 1; i <= n; ++i) {
    int x = arr[i];
    if (two != -1) {
      zero += 2;
      sign = 1;
      shifter = 0;
      one.clear();
      if (two < x) {
        one.insert(make_pair(x - two, x - two));
      }
    } else if (!one.empty()) {
      zero++;
      if (sign == -1) {
        long long lim = shifter - x;
        while (!one.empty() && one.begin()->second <= lim) {
          one.erase(one.begin());
        }
        if (!one.empty() && one.begin()->first <= lim) {
          pair<long long, long long> it =
              make_pair(lim + 1, one.begin()->second);
          one.erase(one.begin());
          assert(it.first <= it.second);
          one.insert(it);
        }
      } else {
        long long lim = x - shifter;
        while (!one.empty() && one.rbegin()->first >= lim) {
          one.erase(--one.end());
        }
        if (!one.empty() && one.rbegin()->second >= lim) {
          pair<long long, long long> it =
              make_pair(one.rbegin()->first, lim - 1);
          one.erase(--one.end());
          assert(it.first <= it.second);
          one.insert(it);
        }
      }
      shifter = x - shifter;
      sign *= -1;
    } else {
      sign = -1;
      shifter = x;
      int lim = min(arr[i - 1] - 1, x - 1);
      if (1 <= lim) {
        one.insert(make_pair(1, lim));
      }
    }
    two = -1;
    if (x % 2 == 0) {
      int y = x / 2;
      long long val = (y - shifter) / sign;
      auto it = one.lower_bound(make_pair(val + 1, (long long)-1e18));
      bool found = 0;
      if (it != one.begin()) {
        --it;
        if (it->first <= val && val <= it->second) {
          found = 1;
        }
      }
      if (found) {
        two = y;
      } else {
        one.insert(make_pair(val, val));
      }
    }
  }
  int ans;
  if (two != -1) {
    ans = zero + 2;
  } else if (!one.empty()) {
    ans = zero + 1;
  } else {
    ans = zero;
  }
  printf("%d\n", 2 * n - ans);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    solve();
  }
  return 0;
}
