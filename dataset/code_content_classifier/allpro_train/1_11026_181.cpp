#include <bits/stdc++.h>
bool flag;
using namespace std;
int main() {
  vector<pair<long long, long long> > vc;
  long long s, n, a, b;
  cin >> s >> n;
  while (n--) {
    cin >> a >> b;
    vc.push_back(make_pair(a, b));
  }
  sort(vc.begin(), vc.end());
  for (long long i = 0; i < vc.size(); i++) {
    if (vc[i].first >= s) {
      cout << "NO\n";
      return 0;
    }
    s += vc[i].second;
  }
  cout << "YES\n";
  return 0;
}
