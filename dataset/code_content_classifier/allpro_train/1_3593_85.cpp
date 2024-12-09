#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
double fixAngle(double A) { return A > 1 ? 1 : (A < -1 ? -1 : A); }
double dcmp(double a, double b) {
  return fabs(a - b) < 1e-6 ? 0 : a > b ? 1 : -1;
}
const int MAX = 2 * 100500;
set<int> setnums;
map<int, int> rnk;
vector<int> nums;
vector<int> pos[MAX];
int segtree[4 * MAX];
void build(int L, int R, int idx) {
  if (L == R) {
    segtree[idx] = nums[L];
    return;
  }
  build(L, (L + R) / 2, idx * 2);
  build((L + R) / 2 + 1, R, idx * 2 + 1);
  segtree[idx] = min(segtree[idx * 2], segtree[idx * 2 + 1]);
}
int query(int L, int R, int tl, int tr, int idx) {
  if (tl <= L && tr >= R) {
    return segtree[idx];
  }
  if (tl > R || tr < L) return 1000000000;
  return min(query(L, (L + R) / 2, tl, tr, idx * 2),
             query((L + R) / 2 + 1, R, tl, tr, idx * 2 + 1));
}
int answer[MAX];
int main() {
  int n;
  scanf("%d", &n);
  nums.resize(n);
  for (long long i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
    setnums.insert(nums[i]);
  }
  int r = 0;
  for (int x : setnums) {
    rnk[x] = r++;
  }
  for (long long i = 0; i < n; i++) {
    pos[rnk[nums[i]]].push_back(i);
  }
  build(0, n - 1, 1);
  queue<pair<long long, long long> > q;
  q.push({0, n - 1});
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    if (t.second < t.first) continue;
    int idx = t.first;
    int mininrange = query(0, n - 1, t.first, t.second, 1);
    int rnkofmin = rnk[mininrange];
    if (mininrange > answer[t.second - t.first + 1]) {
      answer[t.second - t.first + 1] =
          max(answer[t.second - t.first + 1], mininrange);
    }
    auto it = lower_bound(pos[rnkofmin].begin(), pos[rnkofmin].end(), t.first);
    while (it != pos[rnkofmin].end() && (*it) <= t.second) {
      q.push({idx, (*it) - 1});
      idx = (*it) + 1;
      it++;
    }
    q.push({idx, t.second});
  }
  int last = 0;
  for (int i = n; i >= 1; i--) {
    if (answer[i] == 0)
      answer[i] = last;
    else {
      answer[i] = max(last, answer[i]);
      last = answer[i];
    }
  }
  for (long long i = 0; i < n; i++) {
    printf("%d ", answer[i + 1]);
  }
}
