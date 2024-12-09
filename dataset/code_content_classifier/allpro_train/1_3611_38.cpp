#include <bits/stdc++.h>
using namespace std;
const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 17;
const int mod3 = 1e9 + 19;
long long N, M, S, E, V, s[100001], e[100001], Q;
vector<long long> ss, ee;
int main() {
  scanf("%lld %lld %lld %lld %lld", &N, &M, &S, &E, &V);
  for (int i = 0; i < S; i++) {
    scanf("%lld", s + i);
    ss.push_back(s[i]);
  }
  for (int i = 0; i < E; i++) {
    scanf("%lld", e + i);
    ee.push_back(e[i]);
  }
  sort(ss.begin(), ss.end());
  sort(ee.begin(), ee.end());
  scanf("%lld", &Q);
  while (Q--) {
    long long x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld", &y1, &x1, &y2, &x2);
    long long sl = 1e16, sr = 1e16, el = 1e16, er = 1e16;
    if (!ss.empty()) {
      auto lit = upper_bound(ss.begin(), ss.end(), x1);
      auto rit = lower_bound(ss.begin(), ss.end(), x1);
      if (lit != ss.begin()) --lit;
      if (rit == ss.end()) --rit;
      sl = *lit, sr = *rit;
    }
    if (!ee.empty()) {
      auto lit = upper_bound(ee.begin(), ee.end(), x1);
      auto rit = lower_bound(ee.begin(), ee.end(), x1);
      if (lit != ee.begin()) lit--;
      if (rit == ee.end()) rit--;
      el = *lit, er = *rit;
    }
    long long diff = abs(y2 - y1);
    long long ev =
        min(abs(x1 - el) + abs(x2 - el), abs(x1 - er) + abs(x2 - er)) +
        diff / V + (diff % V ? 1 : 0);
    long long sv =
        min(abs(x1 - sl) + abs(x2 - sl), abs(x1 - sr) + abs(x2 - sr)) + diff;
    if (!diff) ev = abs(x1 - x2);
    printf("%lld\n", min(sv, ev));
  }
  return 0;
}
