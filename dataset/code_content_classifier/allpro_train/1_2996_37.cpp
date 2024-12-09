#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(10);
  cout << fixed;
  long long n, t, v;
  cin >> n;
  long long cntOvertake = 0;
  bool overtake = true;
  long long ans = 0;
  long long curVel = 0;
  deque<long long> q;
  for (long long i = 0; i < n; i++) {
    cin >> t;
    if (t == 1) {
      cin >> v;
      curVel = v;
    } else if (t == 2) {
      if (!overtake) ans += cntOvertake;
      cntOvertake = 0;
    } else if (t == 3) {
      cin >> v;
      q.push_back(v);
    } else if (t == 4) {
      cntOvertake = 0;
      overtake = true;
    } else if (t == 5) {
      while (!q.empty()) q.pop_front();
    } else {
      cntOvertake++;
      overtake = false;
    }
    while (!q.empty()) {
      long long vel = q.back();
      if (vel < curVel) {
        ans++;
        q.pop_back();
      } else {
        break;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
