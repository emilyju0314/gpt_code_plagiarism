#include <bits/stdc++.h>
using namespace std;
struct Plan {
  bool is_left;
  long long c;
  long long p;
  Plan(bool _is_left, long long _c, long long _p)
      : is_left(_is_left), c(_c), p(_p) {}
  bool operator<(Plan other) const { return c < other.c; }
};
const int MAXN = 1000000 + 100;
long long counts[MAXN];
long long prices[MAXN];
void update(int idx, long long count, long long price) {
  if (idx == 0) {
    return;
  }
  while (idx < MAXN) {
    counts[idx] += count;
    prices[idx] += price;
    idx += idx & -idx;
  }
}
long long get_sum(long long *base, int idx) {
  long long ans = 0;
  while (idx > 0) {
    ans += base[idx];
    idx -= idx & -idx;
  }
  return ans;
}
class State {
 public:
  State(int _cores) : cores(_cores) {}
  void add(const Plan &plan) {
    if (plan.is_left) {
      update(plan.p, plan.c, (long long)plan.p * plan.c);
    } else {
      update(plan.p, -plan.c, (long long)plan.p * plan.c * -1);
    }
  }
  long long get(int last_pos, int pos) {
    int l = 1, r = MAXN;
    while (l < r) {
      int mid = (l + r) / 2;
      long long cnt = get_sum(counts, mid);
      if (cnt < cores) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    long long value = get_sum(prices, l - 1);
    if (r < MAXN) {
      long long total_price = get_sum(prices, l) - get_sum(prices, l - 1);
      long long base_cc = get_sum(counts, l - 1);
      long long cc = get_sum(counts, l) - base_cc;
      assert(cores >= base_cc);
      if (cc != 0) {
        value += total_price / cc * (cores - base_cc);
      }
    }
    return value * (pos - last_pos);
  }

 private:
  int cores;
};
vector<pair<int, Plan> > plans;
int main() {
  int n, cores, m;
  scanf("%d%d%d", &n, &cores, &m);
  for (int i = 0; i < m; i++) {
    int l, r, c, p;
    scanf("%d%d%d%d", &l, &r, &c, &p);
    plans.push_back(make_pair(l, Plan(true, c, p)));
    plans.push_back(make_pair(r + 1, Plan(false, c, p)));
  }
  sort(plans.begin(), plans.end());
  State state(cores);
  int last_value = 0;
  long long ans = 0;
  int j = 0;
  for (int i = 1; i <= n; i++) {
    for (; j < plans.size() && plans[j].first <= i; j++) {
      state.add(plans[j].second);
    }
    ans += state.get(i - 1, i);
  }
  printf("%lld\n", ans);
  return 0;
}
