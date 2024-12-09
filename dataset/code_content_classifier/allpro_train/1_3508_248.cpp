#include <bits/stdc++.h>
using namespace std;
int size_n, size_m;
int result = 0;
vector<int> el(0);
int main() {
  int ii;
  cin >> size_n >> size_m;
  el.resize(size_n);
  for (ii = 0; ii < size_n; ii++) cin >> el[ii];
  sort(el.begin(), el.end());
  for (ii = (size_n - 1); size_m > 0; ii--, result++) size_m -= el[ii];
  cout << result << endl;
  return 0;
}
