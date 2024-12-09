/**
 *    author:  tourist
 *    created: 26.11.2019 17:52:04       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  int low = 1, high = n;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      b[i] = (a[i] >= mid);
    }
    vector<int> seq(1, 1);
    for (int i = 1; i < n; i++) {
      if (b[i] != b[i - 1]) {
        seq.push_back(1);
      } else {
        seq.back() += 1;
      }
    }
    seq[0] += n;
    seq.back() += n;
    int sz = (int) seq.size();
    vector<int> what(sz);
    for (int i = 0; i < sz; i++) {
      what[i] = (b[0] + i) % 2;
    }
    vector<set<pair<int, int>>> inner(2);
    vector<int> delta(2, 0);
    for (int i = 0; i < sz; i++) {
      inner[what[i]].emplace(seq[i], i);
    }
    vector<int> pr(sz);
    vector<int> ne(sz);
    for (int i = 0; i < sz; i++) {
      pr[i] = i - 1;
      ne[i] = i + 1;
    }
    auto Remove = [&](int x) {
      if (ne[x] < sz) {
        pr[ne[x]] = pr[x];
      }
      ne[pr[x]] = ne[x];
    };
    for (char c : s) {
      int u = (c == 'm' ? 0 : 1);
      delta[u] += 1;
      delta[u ^ 1] -= 1;
      while (!inner[u ^ 1].empty() && inner[u ^ 1].begin()->first + delta[u ^ 1] == 0) {
        int me = inner[u ^ 1].begin()->second;
        inner[u ^ 1].erase(inner[u ^ 1].begin());
        inner[u].erase({seq[pr[me]], pr[me]});
        inner[u].erase({seq[ne[me]], ne[me]});
        seq[pr[me]] += seq[ne[me]] + delta[u];
        inner[u].emplace(seq[pr[me]], pr[me]);
        Remove(me);
        Remove(ne[me]);
      }
      if (what[0] == u) {
        inner[u].erase({seq[0], 0});
        seq[0] -= 1;
        inner[u].emplace(seq[0], 0);
      }
    }
    int have = 0;
    int winner = -1;
    for (int i = 0; i < sz; i = ne[i]) {
      have += seq[i] + delta[what[i]];
      if (have >= n + 1) {
        winner = what[i];
        break;
      }
    }
    if (winner == 1) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << low << '\n';
  return 0;
}
