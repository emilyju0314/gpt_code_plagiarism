#include <bits/stdc++.h>
using namespace std;
map<unsigned long long, int> dp[31];
vector<pair<int, int>> create(int a, int b, int k) {
  int mid = (1 << (k - 1)) - 1;
  vector<pair<int, int>> arow;
  if (a <= mid && mid <= b) {
    arow.push_back(make_pair(a, mid - 1));
    arow.push_back(make_pair(0, b - mid - 1));
  } else if (b < mid) {
    arow.push_back(make_pair(a, b));
  } else if (a > mid) {
    arow.push_back(make_pair(a - mid - 1, b - mid - 1));
  } else {
    assert(false);
  }
  return arow;
}
int lcs(int k, int a, int b, int l, int r) {
  if (k == 0 || a > b || l > r) return 0;
  if (a > l) {
    swap(a, l);
    swap(b, r);
  }
  unsigned long long hsh = 0;
  hsh = hsh * 31 + a + 1;
  hsh = hsh * 31 + b + 1;
  hsh = hsh * 31 + l + 1;
  hsh = hsh * 31 + r + 1;
  if (dp[k].count(hsh)) return dp[k][hsh];
  vector<pair<int, int>> arow = create(a, b, k), brow = create(l, r, k);
  int rig = min(r, b);
  int lef = max(l, a);
  int& ans = dp[k][hsh] = 0;
  if (lef <= rig) {
    ans = max(ans, rig - lef + 1);
  }
  for (auto& it : arow) {
    for (auto& it2 : brow) {
      ans = max(ans, lcs(k - 1, it.first, it.second, it2.first, it2.second));
    }
  }
  return ans;
}
int main() {
  int a, b, l, r;
  scanf("%d%d%d%d", &a, &b, &l, &r);
  --a, --b, --l, --r;
  printf("%d\n", lcs(30, a, b, l, r));
}
