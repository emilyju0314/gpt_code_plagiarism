#include <bits/stdc++.h>
using namespace std;
long long v[200100];
int main() {
  int n, m;
  cin >> n >> m;
  set<pair<long long, long long> > ss;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &v[i]);
    ss.insert(pair<long long, long long>(-(v[i] % m), i));
  }
  long long count = 0;
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < n / m; j++) {
      auto it = ss.lower_bound(pair<long long, long long>(-i, 0));
      long long dist;
      if (it != ss.end())
        dist = i + it->first;
      else {
        --it;
        dist = m + it->first + i;
      }
      v[it->second] += dist;
      count += dist;
      ss.erase(it);
    }
  }
  cout << count << endl;
  cout << v[0];
  for (int i = 1; i < n; i++) printf(" %lld", v[i]);
  cout << endl;
  return 0;
}
