#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v, v1;
  long long a, b, c, d, e, f, g, h, i, j, k, l;
  cin >> a;
  for (i = 0; i < a; i++) {
    v.clear();
    v1.clear();
    cin >> b >> c >> d;
    vector<long long> ans(3, 0);
    ans[0] = b;
    ans[1] = c;
    ans[2] = d;
    sort(ans.begin(), ans.end());
    d = sqrt(ans[0] * ans[0] + pow((ans[2] - ans[1]), 2));
    cout << d << endl;
  }
}
