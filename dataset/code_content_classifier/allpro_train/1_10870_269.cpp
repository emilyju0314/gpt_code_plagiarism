#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) cin >> a[i];
  int m1 = 0;
  int start = 0, end = 0, x = 0, y = 0;
  while (end < n) {
    mp[a[end]]++;
    if (mp.size() > k) {
      mp[a[start]] -= 1;
      if (mp[a[start]] == 0) mp.erase(a[start]);
      start += 1;
    }
    if (m1 < end - start + 1) {
      m1 = end - start + 1;
      x = start;
      y = end;
    }
    end += 1;
  }
  cout << x + 1 << " " << y + 1;
  return 0;
}
