#include <bits/stdc++.h>
using namespace std;
int n, Q;
long long s[100010], q[100010];
vector<long long> dif;
vector<pair<long long, int> > v;
multiset<int> ss;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &s[i]);
  sort(s + 1, s + 1 + n);
  for (int i = 2; i <= n; i++) {
    if (s[i] - s[i - 1] == 0) continue;
    dif.emplace_back(s[i] - s[i - 1]);
  }
  sort(dif.begin(), dif.end());
  long long c = dif.size() + 1;
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    v.emplace_back(r - l, i);
  }
  sort(v.begin(), v.end());
  long long ans = 0, now = 0, id = -1, neg = 0;
  for (auto k : v) {
    long long len = k.first;
    int idx = k.second;
    while (id + 1 < (int)dif.size() && dif[id + 1] <= len) {
      ans += (dif[id + 1] - now) * c - neg * (dif[id + 1] - now);
      now = dif[id + 1];
      neg++;
      id++;
    }
    q[idx] = ans + (len - now + 1) * c - neg * (len - now + 1);
  }
  for (int i = 1; i <= Q; i++) printf("%lld ", q[i]);
  printf("\n");
  return 0;
}
