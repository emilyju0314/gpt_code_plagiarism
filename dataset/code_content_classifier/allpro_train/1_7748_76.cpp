#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, x1, y1;
  cin >> t >> x1 >> y1;
  vector<pair<long long, long long>> v;
  for (long long i = 0; i < t; i++) {
    long long a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  long long count = 0;
  for (long long i = 0; i < v.size(); i++) {
    long long a = y1 - v[i].second;
    long long b = x1 - v[i].first;
    count++;
    for (long long j = i + 1; j < v.size();) {
      if (a * (v[j].first - v[i].first) == b * (v[j].second - v[i].second)) {
        v.erase(v.begin() + j);
      } else {
        j++;
      }
    }
  }
  cout << count << endl;
}
