#include <bits/stdc++.h>
using namespace std;
using ll = signed long long int;
const int MX = 7000 + 10, INF = 3e5, A = 100;
ll res;
pair<ll, ll> ab[MX];
int n;
map<ll, pair<int, ll>> m;
vector<ll> v;
bool ad;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  v.reserve(MX);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ab[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> ab[i].second;
  }
  for (int i = 0; i < n; i++) {
    auto& p = m[ab[i].first];
    p.first++;
    p.second += ab[i].second;
  }
  for (auto it = m.rbegin(); it != m.rend(); it++) {
    auto& p = *it;
    ad = false;
    if (p.second.first >= 2) {
      res += p.second.second;
      v.push_back(p.first);
    } else {
      for (auto i : v) {
        if ((p.first & i) == p.first) {
          res += p.second.second;
          break;
        }
      }
    }
  }
  cout << res;
}
