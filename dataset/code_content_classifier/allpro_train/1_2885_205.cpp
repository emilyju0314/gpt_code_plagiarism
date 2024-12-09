#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int t;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    long long int x;
    cin >> x;
    x--;
    a[x] = -a[x];
  }
  stack<pair<long long int, long long int> > s;
  for (long long int i = n - 1; i >= 0; i--) {
    if (!s.size())
      s.push({a[i], i});
    else {
      auto p = s.top();
      if (abs(a[i]) == abs(p.first)) {
        if (a[i] > 0) {
          if (p.first > 0) a[p.second] = -a[p.second];
          s.pop();
        } else
          s.push({a[i], i});
      } else
        s.push({a[i], i});
    }
  }
  if (!s.size()) {
    cout << "YES\n";
    for (long long int i = 0; i < n; i++) cout << a[i] << " ";
  } else
    cout << "NO";
}
