#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n, tot, flag = 0;
  vector<long long int> v;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 31; i >= 0; i--) {
    tot = (1 << 30) - 1;
    v.clear();
    for (j = 0; j < n; j++) {
      if (a[j] & (1 << i)) {
        v.push_back(a[j]);
        tot = tot & a[j];
      }
    }
    if (tot % (1 << i) == 0 && v.size() >= 1) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    cout << v.size() << endl;
    for (i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
  } else
    cout << "0";
  return 0;
}
