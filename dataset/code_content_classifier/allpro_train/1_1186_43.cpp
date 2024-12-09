#include <bits/stdc++.h>
using namespace std;
vector<int> l, r;
int num[10];
long long ans;
bool can(int pos, bool left_border, bool right_border) {
  if (pos == r.size()) return true;
  if (left_border && right_border) {
    if (l[pos] == r[pos]) {
      if (num[l[pos]] > 0) {
        --num[l[pos]];
        bool res = can(pos + 1, true, true);
        ++num[l[pos]];
        return res;
      }
      return false;
    }
    for (int i = l[pos] + 1; i <= r[pos] - 1; ++i)
      if (num[i] > 0) return true;
    if (num[l[pos]] > 0) {
      --num[l[pos]];
      bool res = can(pos + 1, true, false);
      ++num[l[pos]];
      if (res) return true;
    }
    if (num[r[pos]] > 0) {
      --num[r[pos]];
      bool res = can(pos + 1, false, true);
      ++num[r[pos]];
      return res;
    }
  } else if (left_border) {
    for (int i = l[pos] + 1; i < 10; ++i)
      if (num[i] > 0) return true;
    if (num[l[pos]] > 0) {
      --num[l[pos]];
      bool res = can(pos + 1, true, false);
      ++num[l[pos]];
      return res;
    }
  } else if (right_border) {
    for (int i = 0; i <= r[pos] - 1; ++i)
      if (num[i] > 0) return true;
    if (num[r[pos]] > 0) {
      --num[r[pos]];
      bool res = can(pos + 1, false, true);
      ++num[r[pos]];
      return res;
    }
  }
  return false;
}
void rec(int pos, int min_num) {
  if (pos == r.size()) {
    if (can(0, true, true)) ++ans;
  } else {
    for (int i = min_num; i < 10; ++i) {
      ++num[i];
      rec(pos + 1, i);
      --num[i];
    }
  }
}
int main() {
  long long L, R;
  cin >> L >> R;
  if (L == R) {
    cout << 1;
    return 0;
  }
  bool oneMore = false;
  if (R == 1e18) {
    --R;
    oneMore = true;
  }
  while (R > 0) {
    r.push_back(R % 10);
    R /= 10;
  }
  while (L > 0) {
    l.push_back(L % 10);
    L /= 10;
  }
  while (l.size() < r.size()) l.push_back(0);
  reverse(l.begin(), l.end());
  reverse(r.begin(), r.end());
  rec(0, 0);
  num[0] = r.size() - 1;
  num[1] = 1;
  if (oneMore && !can(0, true, true)) ++ans;
  cout << ans;
  return 0;
}
