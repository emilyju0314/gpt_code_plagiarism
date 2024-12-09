#include <bits/stdc++.h>
using namespace std;
int n, m;
long long int l[200005], r[200005];
long long int a[200005];
int ans[200005];
vector<pair<long long int, pair<int, int> > > p;
set<pair<long long int, int> > s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = int(1); i <= int(n); ++i) {
    cin >> l[i] >> r[i];
  }
  for (int i = int(1); i <= int(n - 1); ++i) {
    long long int a = l[i + 1] - r[i];
    long long int b = r[i + 1] - l[i];
    l[i] = a;
    r[i] = b;
    p.push_back(make_pair(l[i], make_pair(-1, i)));
    p.push_back(make_pair(r[i], make_pair(1, i)));
  }
  for (int i = int(1); i <= int(m); ++i) {
    cin >> a[i];
    p.push_back(make_pair(a[i], make_pair(0, i)));
  }
  sort((p).begin(), (p).end());
  for (int i = 0; i < int((p).size()); i++) {
    if (p[i].second.first == -1) {
      int id = p[i].second.second;
      s.insert(make_pair(r[id], id));
    } else if (p[i].second.first == 1) {
      s.erase(make_pair(p[i].first, p[i].second.second));
    } else {
      if (int((s).size()) > 0) {
        int point_id = p[i].second.second;
        int seg_id = s.begin()->second;
        ans[seg_id] = point_id;
        s.erase(s.begin());
      }
    }
  }
  for (int i = int(1); i <= int(n - 1); ++i) {
    if (ans[i] == 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  for (int i = int(1); i <= int(n - 1); ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}
