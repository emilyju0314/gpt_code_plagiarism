#include <bits/stdc++.h>
using namespace std;
void fastInOut();
const int N = 200001;
int n, k, l, r;
vector<pair<int, int> > in[N];
vector<int> ot[N], ret;
set<pair<int, int> > cur;
int main() {
  fastInOut();
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    in[l].push_back({r, i});
    ot[r].push_back(i);
  }
  for (int i = 1; i < N; ++i) {
    for (auto it : in[i]) cur.insert(it);
    while (int(cur.size()) > k) {
      pair<int, int> lst = *cur.rbegin();
      ret.push_back(lst.second);
      cur.erase(lst);
    }
    for (auto it : ot[i]) cur.erase({i, it});
  }
  sort(ret.begin(), ret.end());
  cout << int(ret.size()) << "\n";
  for (int i = 0; i < int(ret.size()); ++i)
    cout << ret[i] + 1 << " \n"[i == int(ret.size()) - 1];
  return 0;
}
void fastInOut() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
}
