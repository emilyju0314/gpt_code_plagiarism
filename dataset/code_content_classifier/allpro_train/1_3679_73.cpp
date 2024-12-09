#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:256000000")
template <class T>
T sqr(T a) {
  return a * a;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort((b).begin(), (b).end());
  vector<pair<int, int> > res;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) continue;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] == b[i]) {
        res.push_back(make_pair(i, j));
        swap(a[i], a[j]);
        break;
      }
    }
  }
  cout << (int)(res).size() << endl;
  for (int i = 0; i < (int)(res).size(); ++i)
    cout << res[i].first << " " << res[i].second << endl;
  return 0;
}
