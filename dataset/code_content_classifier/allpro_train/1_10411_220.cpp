#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cd = complex<double>;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t--) {
    int n, x, y, na, mchs = 0;
    cin >> n >> x >> y;
    vector<int> v[n + 2], in;
    int ar[n], br[n];
    for (int i = 0; i < n; i++) {
      cin >> br[i];
      v[br[i]].push_back(i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    for (int i = 1; i <= n + 1; i++) {
      if (v[i].size()) {
        pq.push(make_pair(v[i].size(), i));
      } else {
        na = i;
      }
    }
    for (int i = 0; i < x; i++) {
      int ind = pq.top().second, si = pq.top().second;
      pq.pop();
      ar[v[ind].back()] = ind;
      v[ind].pop_back();
      pq.push(make_pair(v[ind].size(), ind));
    }
    vector<int> vv;
    for (int i = 1; i <= n + 1; i++) {
      for (int x : v[i]) {
        vv.push_back(x);
      }
    }
    for (int i = 0; i < vv.size(); i++) {
      int ind = (i + (n - x) / 2) % vv.size();
      ar[vv[ind]] = br[vv[i]];
    }
    for (int i = 0; i < vv.size(); i++) {
      if (ar[vv[i]] == br[vv[i]]) {
        mchs++;
        in.push_back(vv[i]);
      }
    }
    if (mchs > (n - y)) {
      cout << "NO\n";
    } else {
      mchs = n - y;
      cout << "YES\n";
      for (int x : in) {
        ar[x] = na;
        mchs--;
      }
      for (int i = 0; i < n; i++) {
        if (ar[i] != na && ar[i] != br[i] && mchs) {
          mchs--;
          ar[i] = na;
        }
        cout << ar[i] << " ";
      }
      cout << "\n";
    }
  }
}
