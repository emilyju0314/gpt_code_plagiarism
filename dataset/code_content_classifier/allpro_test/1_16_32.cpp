#include <bits/stdc++.h>
using namespace std;
long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};
struct myComp {
  constexpr bool operator()(
      pair<long long, long long> const& a,
      pair<long long, long long> const& b) const noexcept {
    return a.first < b.first;
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long c, d, m, n, k, x, y, maxi = 0, f = 0, mini = LLONG_MAX, sum = 0,
                                 loop;
  string str;
  cin >> loop;
  for (long long _ = (long long)(0); _ < (long long)(loop); _++) {
    cin >> n;
    vector<long long> v(n);
    for (long long i = (long long)(0); i < (long long)(n); i++) cin >> v[i];
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>, myComp>
        q;
    for (long long i = (long long)(0); i < (long long)(n); i++)
      if (v[i] != 0) q.push(pair<long long, long long>(v[i], i + 1));
    pair<long long, long long> a = pair<long long, long long>(0, 0);
    pair<long long, long long> b = pair<long long, long long>(0, 0);
    vector<long long> aq;
    vector<long long> bq;
    while (!q.empty()) {
      if (q.top().first == 0) {
        q.pop();
      } else if (a.first == 0) {
        a = q.top();
        q.pop();
      } else if (b.first == 0) {
        b = q.top();
        q.pop();
      } else {
        a.first--;
        b.first--;
        aq.push_back(a.second);
        bq.push_back(b.second);
        q.push(a);
        q.push(b);
        a = pair<long long, long long>(0, 0);
        b = pair<long long, long long>(0, 0);
      }
    }
    while (a.first > 0 && b.first > 0) {
      a.first--;
      b.first--;
      aq.push_back(a.second);
      bq.push_back(b.second);
    }
    cout << bq.size() << endl;
    for (long long i = (long long)(0); i < (long long)(bq.size()); i++)
      cout << bq[i] << " " << aq[i] << endl;
  }
  return 0;
}
