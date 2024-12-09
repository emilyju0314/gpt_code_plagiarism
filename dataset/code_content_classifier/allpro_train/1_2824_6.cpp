#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const int MAX = 100000;
const long long lim = 1e18;
bool chk(long long x, long long y) { return y <= lim / x; }
void fil(vector<long long> v, vector<long long>& ret) {
  priority_queue<pair<long long, int>> q;
  q.push({-1, 0});
  while (q.size()) {
    long long val = -q.top().first;
    int ind = q.top().second;
    q.pop();
    if (chk(val, v[ind])) {
      ret.push_back(val * v[ind]);
      q.push({-val * v[ind], ind});
    }
    if (ind + 1 < v.size()) {
      q.push({-val, ind + 1});
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> v, vv;
  if (n > 5)
    v.resize(5);
  else
    v.resize((n + 1) / 2);
  vv.resize(n - v.size());
  for (int i = 0; i < v.size(); i++) cin >> v[i];
  for (int i = 0; i < vv.size(); i++) cin >> vv[i];
  long long k;
  cin >> k;
  vector<long long> ret1, ret2;
  ret1.push_back(1);
  ret2.push_back(1);
  fil(v, ret1);
  if (vv.size()) fil(vv, ret2);
  sort(ret1.begin(), ret1.end());
  sort(ret2.begin(), ret2.end());
  long long s = 1, e = 1e18;
  long long res = 1;
  while (s <= e) {
    long long mid = (s + e) / 2ll;
    long long acc = 0;
    for (int i = 0; i < ret1.size(); i++) {
      vector<long long>::iterator it =
          upper_bound(ret2.begin(), ret2.end(), mid / ret1[i]);
      if (it != ret2.begin()) {
        it--;
        acc += (it - ret2.begin() + 1ll);
      }
    }
    if (acc > k)
      e = mid - 1;
    else if (acc < k)
      s = mid + 1;
    else {
      res = mid;
      e = mid - 1;
    }
  }
  cout << res << "\n";
  return 0;
}
