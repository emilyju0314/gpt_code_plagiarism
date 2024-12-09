#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  long long int n, c = 0;
  cin >> n;
  vector<pair<long long int, long long int>> v;
  map<long long int, long long int> mp, mp1;
  for (int i = 0; i < n; i++) {
    long long int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
    mp[x + y]++;
    mp1[x - y]++;
  }
  for (int i = 0; i <= 2000; i++) {
    c = c + (mp[i] * mp[i] - mp[i]) / 2;
  }
  for (int i = -1000; i <= 1000; i++) {
    c = c + (mp1[i] * mp1[i] - mp1[i]) / 2;
  }
  cout << c;
}
