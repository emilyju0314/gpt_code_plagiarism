#include <bits/stdc++.h>
using namespace std;
long long int a[300009];
vector<pair<pair<long long int, long long int>,
            pair<long long int, long long int>>>
    v;
long long int ans = 1;
vector<int> vec;
bool check(int idx, long long int mid) {
  long long int dist, i, j, x, fuel = mid, cnt = v[idx].second.second,
                               kitna_chlegi;
  for (i = v[idx].first.first; i < v[idx].first.second; i++) {
    x = a[i + 1] - a[i];
    kitna_chlegi = fuel / v[idx].second.first;
    if (kitna_chlegi < x) {
      if (cnt == 0 || mid / v[idx].second.first < x) {
        return 0;
      }
      fuel = mid;
      cnt--;
    }
    fuel -= x * v[idx].second.first;
  }
  return 1;
}
void update(int idx) {
  if (check(idx, ans)) {
    return;
  }
  long long int l = ans, r = 1000000000000000000, temp = r;
  bool f;
  while (l <= r) {
    long long int mid = (l + r) / 2;
    f = check(idx, mid);
    if (f) {
      temp = min(temp, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  ans = max(ans, temp);
}
int main() {
  long long int i, j, k, x, y, t, n, m, p;
  scanf("%lld%lld", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (i = 0; i < m; i++) {
    scanf("%lld%lld", &x, &y);
    scanf("%lld%lld", &j, &k);
    v.push_back(make_pair(make_pair(x, y), make_pair(j, k)));
    vec.push_back(i);
  }
  random_shuffle(vec.begin(), vec.end());
  for (i = 0; i < m; i++) {
    update(vec[i]);
  }
  cout << ans << endl;
  ;
}
