#include <bits/stdc++.h>
const unsigned long long INF = 1000000000;
const unsigned long long N = 200000;
const unsigned long long modi = 1000000007;
using namespace std;
int main() {
  unsigned long long n;
  cin >> n;
  vector<pair<unsigned long long, unsigned long long>> v;
  for (unsigned long long i = 0; i < n; i++) {
    unsigned long long x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  unsigned long long sum1 = 0;
  unsigned long long sum2 = 0;
  unsigned long long sum3 = 0;
  unsigned long long sum4 = 0;
  for (unsigned long long i = 0; i < n; i++) {
    sum1 += (v[i].first) * (v[i].first);
    sum2 += v[i].first;
    sum3 += (v[i].second) * (v[i].second);
    sum4 += v[i].second;
  }
  unsigned long long ans = n * (sum1 + sum3) - (sum2 * sum2) - (sum4 * sum4);
  cout << ans << endl;
}
