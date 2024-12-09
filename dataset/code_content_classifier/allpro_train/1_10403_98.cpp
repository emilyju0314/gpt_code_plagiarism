#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, i, j, k, x, cnt = 0, y;
  vector<int> a;
  vector<int> b;
  vector<int> c;
  vector<int> d;
  vector<int> e;
  vector<int> f;
  vector<int> v;
  map<int, int> p;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (x == 4)
      a.push_back(i);
    else if (x == 8)
      b.push_back(i);
    else if (x == 15)
      c.push_back(i);
    else if (x == 16)
      d.push_back(i);
    else if (x == 23)
      e.push_back(i);
    else
      f.push_back(i);
  }
  v.push_back(a.size());
  v.push_back(b.size());
  v.push_back(c.size());
  v.push_back(d.size());
  v.push_back(e.size());
  v.push_back(f.size());
  sort(v.begin(), v.end());
  k = v[0];
  i = 0;
  while (k--) {
    j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    if (j >= b.size() || b.size() == 0) break;
    y = j;
    j = upper_bound(c.begin(), c.end(), b[j]) - c.begin();
    b.erase(b.begin(), b.begin() + y + 1);
    if (j >= c.size() || c.size() == 0) break;
    y = j;
    j = upper_bound(d.begin(), d.end(), c[j]) - d.begin();
    c.erase(c.begin(), c.begin() + y + 1);
    if (j >= d.size() || d.size() == 0) break;
    y = j;
    j = upper_bound(e.begin(), e.end(), d[j]) - e.begin();
    d.erase(d.begin(), d.begin() + y + 1);
    if (j >= e.size() || e.size() == 0) break;
    y = j;
    j = upper_bound(f.begin(), f.end(), e[j]) - f.begin();
    e.erase(e.begin(), e.begin() + y + 1);
    if (j >= f.size() || f.size() == 0) break;
    f.erase(f.begin(), f.begin() + j + 1);
    i++;
    cnt++;
  }
  cout << n - cnt * 6;
}
