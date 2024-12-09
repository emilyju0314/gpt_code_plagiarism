#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  long long s = 0;
  vector<int> a(n);
  vector<long long> b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    s += a[i];
    s += b[(i % m)];
    b[(i % m)] += a[i];
    cout << s << " ";
  }
}
