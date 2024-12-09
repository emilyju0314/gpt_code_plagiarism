#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, k;
  cin >> n >> k;
  long long int aa[n];
  vector<long long int> a;
  long long int i;
  for (i = 0; i < n; i++) cin >> aa[i], a.push_back(aa[i]);
  if (k == 1) {
    cout << n << endl;
    exit(0);
  }
  sort(a.begin(), a.end());
  set<long long int> s;
  s.insert(a[0]);
  long long int count = 1, l = 1;
  count = 1;
  l = 1;
  long long int z, x, q, out = 0;
  while (1) {
    if (s.empty() == true) {
      if (l >= a.size()) break;
      s.insert(a[l]);
      count++;
      l++;
      if (l >= a.size()) break;
    }
    z = *(s.begin());
    s.erase(s.begin());
    x = z * k;
    auto qq = lower_bound(a.begin(), a.end(), x);
    if (qq != a.end()) {
      q = qq - a.begin();
      for (i = l; i < q; i++) {
        if (a[i] == x) {
          break;
        }
        count++;
        s.insert(a[i]);
      }
      if (a[q] == x) q++;
      l = q;
    } else {
      count += a.size() - l;
      break;
    }
  }
  cout << count << endl;
}
