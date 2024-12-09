#include <bits/stdc++.h>
using namespace std;
template <typename T>
unsigned long long gr(T v) {
  typename T::value_type last = v[0];
  unsigned long long res = 0;
  unsigned long long counter = -1;
  for (const auto& arg : v) {
    ++counter;
    if (arg != last) {
      res += (counter) * (counter - 1) / 2;
      counter = 0;
      last = arg;
    }
  }
  res += (counter + 1) * (counter) / 2;
  return res;
}
int main() {
  unsigned long long n;
  vector<unsigned long long> x;
  vector<unsigned long long> y;
  vector<pair<unsigned long long, unsigned long long> > c;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    unsigned long long tx, ty;
    cin >> tx >> ty;
    x.push_back(tx);
    y.push_back(ty);
    c.push_back(make_pair(tx, ty));
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  sort(c.begin(), c.end());
  cout << gr(x) + gr(y) - gr(c) << endl;
  return 0;
}
