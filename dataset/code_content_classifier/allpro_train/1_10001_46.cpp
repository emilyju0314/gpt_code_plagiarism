#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
template <class T>
int size(T &x) {
  return x.size();
}
vector<pair<int, int> > vals;
long double P(int no, int lo, int hi) {
  lo = max(lo, vals[no].first);
  hi = min(hi, vals[no].second);
  if (lo > hi) return 0.0;
  return static_cast<long double>(hi - lo + 1) /
         (vals[no].second - vals[no].first + 1);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    vals.push_back(pair<int, int>(a, b));
  }
  long long cnt = 0;
  long double res = 0;
  for (int winner = 0; winner < n; winner++) {
    for (int seconds = 1; seconds < (1 << n); seconds++) {
      if (seconds == (1 << winner)) continue;
      if (seconds & (1 << winner)) {
        bool bad = false;
        for (int lower = 0; lower < winner; lower++) {
          if (seconds & (1 << lower)) {
            bad = true;
            break;
          }
        }
        if (bad) {
          continue;
        }
      }
      for (int second = 0; second <= 11000; second++) {
        long double prob = 1.0;
        for (int i = 0; i < n; i++) {
          if (seconds & (1 << i)) {
            prob *= P(i, second, second);
          } else if (i == winner) {
            prob *= P(i, second + 1, 11000);
          } else {
            prob *= P(i, 0, second - 1);
          }
        }
        res += prob * second;
        cnt++;
      }
    }
  }
  cout << setprecision(12) << fixed << res << endl;
  return 0;
}
