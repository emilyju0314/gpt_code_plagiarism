#include <bits/stdc++.h>
using namespace std;
const long long MX = 2e5 + 10, MD = 1e9 + 7, SQ = 2200;
long long n, m, a[MX], ans[MX], q, b[MX], cnt[MX], le, ri, tim, num[MX];
vector<pair<pair<long long, long long>, pair<long long, long long> > > query;
vector<long long> v;
pair<long long, long long> change[MX], reverse_change[MX];
void Add(long long x) {
  if (num[a[x]] != 0) cnt[num[a[x]]]--;
  num[a[x]]++;
  if (num[a[x]] > 0) cnt[num[a[x]]]++;
}
void Remove(long long x) {
  if (num[a[x]] != 0) cnt[num[a[x]]]--;
  num[a[x]]--;
  if (num[a[x]] > 0) cnt[num[a[x]]]++;
}
void Change(long long x, long long y) {
  if (x < le || x > ri) {
    a[x] = y;
    return;
  }
  Remove(x);
  a[x] = y;
  Add(x);
}
bool CMP(pair<pair<long long, long long>, pair<long long, long long> > A,
         pair<pair<long long, long long>, pair<long long, long long> > B) {
  if (A.first.first / SQ != B.first.first / SQ)
    return A.first.first < B.first.first;
  if (A.first.second / SQ != B.first.second / SQ)
    return A.first.second < B.first.second;
  return A.second.first < B.second.first;
}
int32_t main() {
  scanf("%lld%lld", &n, &q);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    v.push_back(a[i]);
  }
  long long tmp = 0, tmp2 = 0;
  for (long long i = 1; i <= q; i++) {
    long long t, l, r;
    scanf("%lld%lld%lld", &t, &l, &r);
    if (t == 2) {
      tmp++;
      change[tmp] = {l, r};
      v.push_back(r);
    } else {
      tmp2++;
      query.push_back({{l, r}, {tmp, tmp2}});
    }
  }
  sort(query.begin(), query.end(), CMP);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (long long i = 1; i <= n; i++)
    a[i] = (upper_bound(v.begin(), v.end(), a[i]) - v.begin()), b[i] = a[i];
  for (long long i = 1; i <= tmp; i++) {
    change[i].second =
        (upper_bound(v.begin(), v.end(), change[i].second) - v.begin());
    reverse_change[i].first = change[i].first;
    reverse_change[i].second = b[change[i].first];
    b[change[i].first] = change[i].second;
  }
  for (auto pa : query) {
    long long l = pa.first.first, r = pa.first.second, t = pa.second.first,
              id = pa.second.second;
    while (ri < r) ri++, Add(ri);
    while (le > l) le--, Add(le);
    while (ri > r) Remove(ri), ri--;
    while (le < l) Remove(le), le++;
    while (tim < t) tim++, Change(change[tim].first, change[tim].second);
    while (tim > t)
      Change(reverse_change[tim].first, reverse_change[tim].second), tim--;
    for (long long i = 1; i < 600; i++) {
      if (cnt[i] == 0) {
        ans[id] = i;
        break;
      }
    }
  }
  for (long long i = 1; i <= tmp2; i++) printf("%lld\n", ans[i]);
}
