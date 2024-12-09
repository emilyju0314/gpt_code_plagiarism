#include <bits/stdc++.h>
using namespace std;
vector<int> converter(long long i, int j) {
  vector<int> v;
  int rem;
  while (abs(i) >= abs(j)) {
    rem = i % j;
    if (rem < 0) {
      rem = abs(j) + i % j;
      i = i / j;
      i++;
    } else {
      rem = i % j;
      i = i / j;
    }
    v.push_back(rem);
  }
  if (i < 0) {
    v.push_back(abs(j) + i);
    v.push_back(1);
  } else
    v.push_back(i);
  return v;
}
int main() {
  long long i;
  int j;
  cin >> i >> j;
  j = -j;
  vector<int> v = converter(i, j);
  cout << v.size() << endl;
  for (auto i : v) {
    cout << i << " ";
  }
  return 0;
}
