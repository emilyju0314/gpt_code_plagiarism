#include <bits/stdc++.h>
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long MAXN = 1e6;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
using namespace std;
bool f1(vector<pair<long long, pair<long double, long double>>> v) {
  sort(v.begin(), v.end());
  do {
    long double ans1 = sqrt((v[0].second.first - v[2].second.first) *
                                (v[0].second.first - v[2].second.first) +
                            (v[0].second.second - v[2].second.second) *
                                (v[0].second.second - v[2].second.second));
    long double ans2 = sqrt((v[1].second.first - v[3].second.first) *
                                (v[1].second.first - v[3].second.first) +
                            (v[1].second.second - v[3].second.second) *
                                (v[1].second.second - v[3].second.second));
    if (abs(ans1 - ans2) <= eps) {
      long double ans3 = sqrt((v[0].second.first - v[1].second.first) *
                                  (v[0].second.first - v[1].second.first) +
                              (v[0].second.second - v[1].second.second) *
                                  (v[0].second.second - v[1].second.second));
      long double ans4 = sqrt((v[1].second.first - v[2].second.first) *
                                  (v[1].second.first - v[2].second.first) +
                              (v[1].second.second - v[2].second.second) *
                                  (v[1].second.second - v[2].second.second));
      long double ans5 = sqrt((v[2].second.first - v[3].second.first) *
                                  (v[2].second.first - v[3].second.first) +
                              (v[2].second.second - v[3].second.second) *
                                  (v[2].second.second - v[3].second.second));
      long double ans6 = sqrt((v[0].second.first - v[3].second.first) *
                                  (v[0].second.first - v[3].second.first) +
                              (v[0].second.second - v[3].second.second) *
                                  (v[0].second.second - v[3].second.second));
      if (ans3 * ans4 > 0 && abs(ans3 - ans4) <= eps &&
          abs(ans4 - ans5) <= eps && abs(ans5 - ans6) <= eps &&
          abs(ans6 - ans3) <= eps)
        return 1;
    }
  } while (next_permutation(v.begin(), v.end()));
  return 0;
}
bool f2(vector<pair<long long, pair<long double, long double>>> v) {
  sort(v.begin(), v.end());
  do {
    long double ans1 = sqrt((v[0].second.first - v[2].second.first) *
                                (v[0].second.first - v[2].second.first) +
                            (v[0].second.second - v[2].second.second) *
                                (v[0].second.second - v[2].second.second));
    long double ans2 = sqrt((v[1].second.first - v[3].second.first) *
                                (v[1].second.first - v[3].second.first) +
                            (v[1].second.second - v[3].second.second) *
                                (v[1].second.second - v[3].second.second));
    if (abs(ans1 - ans2) <= eps) {
      long double ans3 = sqrt((v[0].second.first - v[1].second.first) *
                                  (v[0].second.first - v[1].second.first) +
                              (v[0].second.second - v[1].second.second) *
                                  (v[0].second.second - v[1].second.second));
      long double ans4 = sqrt((v[1].second.first - v[2].second.first) *
                                  (v[1].second.first - v[2].second.first) +
                              (v[1].second.second - v[2].second.second) *
                                  (v[1].second.second - v[2].second.second));
      long double ans5 = sqrt((v[2].second.first - v[3].second.first) *
                                  (v[2].second.first - v[3].second.first) +
                              (v[2].second.second - v[3].second.second) *
                                  (v[2].second.second - v[3].second.second));
      long double ans6 = sqrt((v[0].second.first - v[3].second.first) *
                                  (v[0].second.first - v[3].second.first) +
                              (v[0].second.second - v[3].second.second) *
                                  (v[0].second.second - v[3].second.second));
      if (abs(ans3 - ans5) <= eps && abs(ans4 - ans6) <= eps && ans3 * ans4 > 0)
        return 1;
    }
  } while (next_permutation(v.begin(), v.end()));
  return 0;
}
long double x[MAXN], y[MAXN];
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  for (int i = 0; i < 8; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int mask = 0; mask < (1ll << 8); ++mask) {
    if (__builtin_popcount(mask) == 4) {
      vector<pair<long long, pair<long double, long double>>> v1, v2;
      for (int j = 0; j < 8; ++j)
        if (((1ll << j) & mask) == 0)
          v2.push_back(make_pair(j, make_pair(x[j], y[j])));
        else
          v1.push_back(make_pair(j, make_pair(x[j], y[j])));
      if (f1(v1) && f2(v2)) {
        cout << "YES"
             << "\n";
        for (auto j : v1) cout << j.first + 1 << " ";
        cout << "\n";
        for (auto j : v2) cout << j.first + 1 << " ";
        cout << "\n";
        return 0;
      }
    }
  }
  cout << "NO"
       << "\n";
  return 0;
}
