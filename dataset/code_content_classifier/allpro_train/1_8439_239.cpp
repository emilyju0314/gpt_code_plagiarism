#include <bits/stdc++.h>
using namespace std;
long long inp;
long long i1, i2, i3, i4, i5, i6, i7, i8;
long long MOD = (long long)1e9 + 7, MOD2 = (long long)1e9 + 9;
double eps = 1e-9;
long long TMP =
    (chrono::high_resolution_clock::now().time_since_epoch().count() % MOD +
     MOD) %
    MOD;
auto STTMP = chrono::steady_clock::now();
struct pqs {
  long long first, second, third;
  pqs(long long first, long long second, long long third)
      : first(first), second(second), third(third) {}
  bool operator<(const pqs& p2) const {
    if (second != p2.second) {
      return second > p2.second;
    } else {
      return third > p2.third;
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  srand(TMP);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<long long, long long>>> g(n);
  for (long long i = (0); i < (m); i++) {
    cin >> i1 >> i2 >> i3;
    i1--;
    i2--;
    g.at(i1).push_back({i2, i3});
    g.at(i2).push_back({i1, i3});
  }
  vector<long long> vis(n);
  vis.at(0) = 1;
  vector<long long> shortd(n, 100000);
  shortd.at(0) = 0;
  priority_queue<pqs> pq;
  vector<long long> tr, tr2;
  for (long long i = (0); i < (k); i++) {
    cin >> i1 >> i2;
    i1--;
    tr.push_back(i1);
    tr2.push_back(i2);
    pqs tmp(i1, i2, 1ll);
    pq.push({tmp});
  }
  for (long long i = (0); i < (g.at(0).size()); i++) {
    pqs tmp(g.at(0).at(i).first, g.at(0).at(i).second, 0ll);
    pq.push({tmp});
  }
  long long res = 0;
  while (!pq.empty()) {
    long long nextp = pq.top().first;
    long long time = pq.top().second;
    bool ist = pq.top().third;
    pq.pop();
    if (!vis.at(nextp)) {
      if (ist) {
        res--;
      }
      vis.at(nextp) = 1;
      shortd.at(nextp) = min(shortd.at(nextp), time);
      for (long long i = (0); i < (g.at(nextp).size()); i++) {
        pqs tmp(g.at(nextp).at(i).first, g.at(nextp).at(i).second + time, 0ll);
        pq.push({tmp});
      }
    }
  }
  cout << res + k;
  return 0;
}
