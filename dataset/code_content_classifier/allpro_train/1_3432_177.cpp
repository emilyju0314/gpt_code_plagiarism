#include <bits/stdc++.h>
using namespace std;
bool findEqual(int x, int n) {
  int sum = x, tem = x;
  while (tem != 0) {
    sum += (tem % 10);
    tem /= 10;
  }
  if (sum == n) {
    return true;
  } else {
    return false;
  }
}
int main() {
  long long n;
  cin >> n;
  vector<int> v;
  int cnt = 0;
  if (n < 200) {
    for (int i = 1; i <= n; i++) {
      if (findEqual(i, n)) {
        v.push_back(i);
      }
    }
  } else {
    for (int i = n; i >= n - 100; i--) {
      if (findEqual(i, n)) {
        v.push_back(i);
      }
    }
  }
  cout << v.size() << endl;
  sort(v.begin(), v.end());
  for (auto x : v) {
    cout << x << endl;
  }
  return 0;
}
