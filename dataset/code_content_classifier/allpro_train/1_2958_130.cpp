#include <bits/stdc++.h>
using namespace std;
const long long int big = 10e10 + 11;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n), v1(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> v1[i];
    int bar = 0, kom = 0, flag = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == v1[i])
        ;
      else if (v[i] > v1[i]) {
        if (kom)
          ;
        else {
          flag = 1;
          break;
        }
      } else {
        if (bar)
          ;
        else {
          flag = 1;
          break;
        }
      }
      if (v[i] == 1)
        bar = 1;
      else if (v[i])
        kom = 1;
    }
    if (flag)
      cout << "NO\n";
    else
      cout << "YES\n";
    v.clear();
    v1.clear();
  }
  return 0;
}
