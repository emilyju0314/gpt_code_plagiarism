#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 123;
int n;
long double a[N], k[N], b[N], bur[N], res[N];
map<long double, vector<int> > mp;
set<long double> st;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long double tmp = 0;
  for (int i = 1; i <= n; i++) {
    cin >> k[i] >> b[i];
    long double x = 0;
    if (k[i] != 0.) {
      x = -b[i] / k[i];
      st.insert(x);
      mp[x].push_back(i);
    }
    long double y = k[i] * -1e18 + b[i];
    if (y > 0) tmp += y;
  }
  int len = 1;
  a[1] = -1e18;
  while (st.size()) {
    long double x = *st.begin();
    st.erase(x);
    a[++len] = x;
  }
  res[1] = tmp;
  for (int i = 2; i <= len; i++) {
    for (auto it : mp[a[i - 1]]) {
      long double y = k[it] * a[i] + b[it];
      long double z = k[it] * a[i - 1] + b[it];
      if (z > 0) tmp -= z;
      if (y > 0) tmp += y;
    }
    res[i] = tmp;
    long double dy = res[i] - res[i - 1];
    long double dx = a[i] - a[i - 1];
    long double coef = dy / dx;
    long double ang = atan(coef);
    bur[i] = ang;
  }
  int cnt = 0;
  for (int i = 2; i <= len; i++)
    if ((bur[i] - bur[i - 1]) * 180. != 180. * atan(-1)) cnt++;
  cout << cnt;
  return 0;
}
