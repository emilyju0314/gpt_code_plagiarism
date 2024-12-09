#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c / 2);
  v.push_back(d / 7);
  v.push_back(e / 4);
  sort((v).begin(), (v).end());
  cout << v[0] << endl;
  return 0;
}
