#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long po(long long base, long long powerRaised) {
  if (powerRaised != 0)
    return (base * po(base, powerRaised - 1));
  else
    return 1;
}
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  if (abs(a.first) < abs(b.first))
    return true;
  else if (abs(a.first) > abs(b.first))
    return false;
  else {
    if (abs(a.second) > abs(b.second))
      return false;
    else
      return true;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v;
  long long cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
    if (x == 0) cnt1++;
    if (y == 0) cnt2++;
  }
  cout << 6 * v.size() - 2 * (cnt1 + cnt2) << "\n";
  sort(v.begin(), v.end(), compare);
  for (int i = 0; i < n; i++) {
    if (v[i].first > 0)
      cout << 1 << " " << v[i].first << " " << 'R' << "\n";
    else if (v[i].first < 0)
      cout << 1 << " " << -1 * v[i].first << " " << 'L' << "\n";
    if (v[i].second > 0)
      cout << 1 << " " << v[i].second << " " << 'U' << "\n";
    else if (v[i].second < 0)
      cout << 1 << " " << -1 * v[i].second << " " << 'D' << "\n";
    cout << "2"
         << "\n";
    if (v[i].first > 0)
      cout << 1 << " " << v[i].first << " " << 'L' << "\n";
    else if (v[i].first < 0)
      cout << 1 << " " << -1 * v[i].first << " " << 'R' << "\n";
    if (v[i].second > 0)
      cout << 1 << " " << v[i].second << " " << 'D' << "\n";
    else if (v[i].second < 0)
      cout << 1 << " " << -1 * v[i].second << " " << 'U' << "\n";
    cout << 3 << "\n";
  }
  return 0;
}
