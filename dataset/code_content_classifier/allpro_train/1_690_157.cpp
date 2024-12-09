#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, int> > v;
long long cnt[200005];
int main() {
  int n;
  cin >> n;
  long long a, b;
  long long on = 1;
  for (int i = 0; i < n; i++) {
    cnt[i + 1] = 0;
    cin >> a >> b;
    b++;
    v.push_back(make_pair(a, 1));
    v.push_back(make_pair(b, -1));
  }
  sort(v.begin(), v.end());
  int c = 0;
  long long prev = -1;
  for (int i = 0; i < v.size(); i++) {
    long long cur = v[i].first;
    if (prev != -1) {
      cnt[c] += cur - prev;
    }
    while (v[i].first == cur) {
      c += v[i].second;
      i++;
    }
    prev = cur;
    i--;
  }
  for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
  return 0;
}
