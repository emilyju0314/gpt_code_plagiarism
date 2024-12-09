#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int tt, i, j, k, l, m, nn, o, p, q, x, y, z;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> nn >> k;
  list<long long int> pp;
  set<long long int> kt;
  cin >> x;
  pp.push_back(x);
  kt.insert(x);
  for (i = 0; i < nn - 1; i++) {
    cin >> p;
    if (kt.find(p) == kt.end()) {
      kt.insert(p);
      if (pp.size() == k) {
        kt.erase(pp.back());
        pp.pop_back();
        pp.push_front(p);
      } else
        pp.push_front(p);
    }
  }
  cout << pp.size() << "\n";
  for (auto i = pp.begin(); i != pp.end(); i++) cout << *i << " ";
  return 0;
}
