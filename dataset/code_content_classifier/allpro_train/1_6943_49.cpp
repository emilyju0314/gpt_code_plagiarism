#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
long double opt(long double lo, long double hi, long double X1, long double Y1,
                long double X2, long double Y2) {
  if (Y1 <= Y2) {
    return X1 - X2 + hi * (Y1 - Y2);
  } else {
    return X1 - X2 + lo * (Y1 - Y2);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  long long A[N], B[N], C[N];
  for (int i = 0; i < (N); i++) cin >> A[i] >> B[i] >> C[i];
  vector<pair<long double, pair<int, int> > > ev;
  vector<pair<long double, pair<int, int> > > pe, pe2;
  for (int i = 0; i < (N); i++) {
    for (int j = 0; j < (N); j++) {
      if (C[i] <= C[j]) continue;
      ev.push_back(
          {((long double)B[j] - A[i]) / ((long double)C[i] - C[j]) - 1e-15,
           {i, j}});
      ev.push_back(
          {((long double)A[j] - B[i]) / ((long double)C[i] - C[j]) + 1e-15,
           {i, j}});
      pe.push_back(
          {((long double)A[j] - A[i]) / ((long double)C[i] - C[j]), {i, j}});
      pe2.push_back(
          {((long double)B[j] - B[i]) / ((long double)C[i] - C[j]), {i, j}});
    }
  }
  if ((int)(ev).size() == 0) {
    long double lo = 1e20, hi = -1e20;
    for (int i = 0; i < (N); i++) {
      ckmin(lo, (long double)A[i]);
      ckmax(hi, (long double)B[i]);
    }
    cout << hi - lo << nl;
    return 0;
  }
  long double ans = 1e20;
  sort(ev.begin(), ev.end());
  vector<pair<long double, int> > is;
  for (int i = 0; i < (N); i++) {
    is.push_back({(ev[0].first - 1) * C[i] + A[i], i});
  }
  sort(is.begin(), is.end());
  int lpos[N], rpos[N];
  for (int i = 0; i < (N); i++) lpos[is[i].second] = i;
  vector<int> lord, rord;
  for (int i = 0; i < (N); i++) lord.push_back(is[i].second);
  is.clear();
  for (int i = 0; i < (N); i++)
    is.push_back({(ev[0].first - 1) * C[i] + B[i], i});
  sort(is.begin(), is.end());
  for (int i = 0; i < (N); i++) rpos[is[i].second] = i;
  for (int i = 0; i < (N); i++) rord.push_back(is[i].second);
  ans = opt(-1e20, ev[0].first, B[rord[N - 1]], C[rord[N - 1]], A[lord[0]],
            C[lord[0]]);
  bool in[N][N];
  for (int i = 0; i < (N); i++)
    for (int j = 0; j < (N); j++) in[i][j] = false;
  int cnt = 0;
  int pind = 0, pind2 = 0;
  sort(pe.begin(), pe.end());
  sort(pe2.begin(), pe2.end());
  for (int i = 0; i < ((int)(ev).size()); i++) {
    auto a = ev[i];
    int L = min(a.second.first, a.second.second);
    int R = max(a.second.first, a.second.second);
    if (in[L][R]) {
      cnt--;
    } else {
      cnt++;
      in[L][R] = true;
    }
    while (pind != (int)(pe).size() && pe[pind].first <= ev[i].first) {
      a = pe[pind];
      pind++;
      if (lpos[a.second.first] > lpos[a.second.second]) continue;
      swap(lord[lpos[a.second.first]], lord[lpos[a.second.second]]);
      swap(lpos[a.second.first], lpos[a.second.second]);
    }
    while (pind2 != (int)(pe2).size() && pe2[pind2].first <= ev[i].first) {
      a = pe2[pind2];
      pind2++;
      if (rpos[a.second.first] > rpos[a.second.second]) continue;
      swap(rord[rpos[a.second.first]], rord[rpos[a.second.second]]);
      swap(rpos[a.second.first], rpos[a.second.second]);
    }
    if (cnt == 0 && i != (int)(ev).size() - 1) {
      ckmin(ans, opt(ev[i].first, ev[i + 1].first, B[rord[N - 1]],
                     C[rord[N - 1]], A[lord[0]], C[lord[0]]));
    }
  }
  ckmin(ans, opt(ev[(int)(ev).size() - 1].first, 1e20, B[rord[N - 1]],
                 C[rord[N - 1]], A[lord[0]], C[lord[0]]));
  cout << setprecision(20) << ans << nl;
  return 0;
}
