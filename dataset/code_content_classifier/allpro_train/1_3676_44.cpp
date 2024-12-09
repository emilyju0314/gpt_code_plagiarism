#include <bits/stdc++.h>
using namespace std;
struct data {
  long long ppl, pay, idx;
};
data obj;
struct data2 {
  long long size, idx;
};
data2 obj2;
bool cmp(data a, data b) {
  if (a.pay == b.pay) return a.ppl < b.ppl;
  return a.pay > b.pay;
}
bool cmp2(data2 a, data2 b) { return a.size < b.size; }
vector<data> v;
vector<pair<long long, long long> > ans;
vector<data2> table;
long long n, c, p, m, k;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> c >> p;
    obj.idx = i;
    obj.pay = p;
    obj.ppl = c;
    v.push_back(obj);
  }
  sort(v.begin(), v.end(), cmp);
  cin >> k;
  for (long long i = 1; i <= k; ++i)
    cin >> m, obj2.idx = i, obj2.size = m, table.push_back(obj2);
  sort(table.begin(), table.end(), cmp2);
  long long x = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < k; ++j) {
      if (table[j].size >= v[i].ppl) {
        table[j].size = -1;
        x += v[i].pay;
        ans.push_back(make_pair(v[i].idx, table[j].idx));
        break;
      }
    }
  }
  cout << ans.size() << " " << x << "\n";
  for (long long i = 0; i < ans.size(); ++i) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
  return 0;
}
