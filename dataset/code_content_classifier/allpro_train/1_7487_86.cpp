#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n;
  cin >> n;
  int s = 1;
  while (s <= n) {
    v.push_back(s);
    s *= 2;
  }
  int x = v[v.size() - 1];
  if (x == n) {
    cout << 1;
    return 0;
  }
  int z = 1;
  for (int i = v.size() - 2; i >= 0; i--) {
    if (x + v[i] > n) continue;
    x += v[i];
    z += 1;
  }
  cout << z;
}
