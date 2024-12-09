#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n, V;
int p[MAXN + 10], t[MAXN + 10];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (n); i++) scanf("%d%d", &p[i], &t[i]);
  scanf("%d", &V);
  vector<pair<long long, long long> > v;
  for (int i = 0; i < (n); i++)
    v.push_back(
        make_pair(t[i] * (long long)V - p[i], t[i] * (long long)V + p[i]));
  sort(v.begin(), v.end());
  vector<long long> vv;
  for (__typeof(v.begin()) i = v.begin(); i != v.end(); ++i)
    if (vv.empty() || vv.back() <= i->second)
      vv.push_back(i->second);
    else
      *upper_bound(vv.begin(), vv.end(), i->second) = i->second;
  int ans2 = vv.size();
  vv.clear();
  for (__typeof(v.begin()) i = v.begin(); i != v.end(); ++i)
    if (i->first >= 0 && i->second >= 0)
      if (vv.empty() || vv.back() <= i->second)
        vv.push_back(i->second);
      else
        *upper_bound(vv.begin(), vv.end(), i->second) = i->second;
  int ans1 = vv.size();
  printf("%d %d\n", ans1, ans2);
  return 0;
}
