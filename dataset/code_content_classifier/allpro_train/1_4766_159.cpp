#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> check(long long a, long long b, long long c,
                                 long long d) {
  if (a > c && a > d) {
    pair<long long, long long> p = {0, 0};
    return p;
  } else if (b < c && b < d) {
    pair<long long, long long> p = {0, 0};
    return p;
  } else {
    a = max(a, c);
    b = min(b, d);
    pair<long long, long long> p = {a, b};
    return p;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<pair<long long, long long>> data(n);
  vector<pair<long long, long long>> up(n);
  vector<pair<long long, long long>> down(n);
  for (long long i = 0; i < n; i++) cin >> data[i].first >> data[i].second;
  up[n - 1] = {data[n - 1].first, data[n - 1].second};
  for (long long i = n - 2; i >= 0; i--) {
    pair<long long, long long> p =
        check(up[i + 1].first, up[i + 1].second, data[i].first, data[i].second);
    up[i] = {p.first, p.second};
  }
  down[0] = {data[0].first, data[0].second};
  for (long long i = 1; i < n; i++) {
    auto p = check(down[i - 1].first, down[i - 1].second, data[i].first,
                   data[i].second);
    down[i] = {p.first, p.second};
  }
  vector<pair<long long, long long>> ans;
  ans.push_back(down[n - 2]);
  ans.push_back(up[1]);
  for (long long i = 1; i < n - 1; i++) {
    auto p = check(up[i + 1].first, up[i + 1].second, down[i - 1].first,
                   down[i - 1].second);
    ans.push_back(p);
  }
  vector<long long> ans1;
  for (auto it : ans) {
    ans1.push_back(abs(it.first - it.second));
  }
  cout << *max_element(ans1.begin(), ans1.end());
  return 0;
}
