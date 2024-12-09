#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const long long int N = 1000001;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int l, r;
  cin >> l >> r;
  vector<long long int> v;
  queue<long long int> q;
  q.push(4);
  q.push(7);
  while (!q.empty()) {
    long long int cur = q.front();
    q.pop();
    if (cur >= 1e10) {
      break;
    }
    v.push_back(cur);
    q.push(cur * 10 + 4);
    q.push(cur * 10 + 7);
  }
  sort(v.begin(), v.end());
  long long int ans = 0;
  while (l <= r) {
    long long int vall = *upper_bound(v.begin(), v.end(), l);
    if (binary_search(v.begin(), v.end(), l)) {
      vall = l;
    }
    ans += (min(r, vall) - l + 1) * vall;
    l = vall + 1;
  }
  cout << ans << "\n";
  return 0;
}
