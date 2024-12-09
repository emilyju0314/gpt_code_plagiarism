#include <bits/stdc++.h>
using namespace std;
vector<int> pos;
int m1[128], m2[128];
int main() {
  int B, D;
  cin >> B >> D;
  string a, c;
  cin >> a >> c;
  int n = c.size();
  for (int i = 0; i < c.size(); i++) {
    m1[i] = 0;
    for (int j = 0; j < a.size(); j++) {
      if (c[(i + m1[i]) % n] == a[j]) m1[i] += 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < B; i++) {
    ans += m1[(ans) % n];
  }
  cout << (ans / c.size()) / D << endl;
  return 0;
}
