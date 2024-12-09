#include <bits/stdc++.h>
using namespace std;
int Max() { return -1000000007; }
int Min() { return 1000000007; }
template <typename... Args>
int Max(int a, Args... args) {
  return max(a, Max(args...));
}
template <typename... Args>
int Min(int a, Args... args) {
  return min(a, Min(args...));
}
long long a[7][7];
int main() {
  for (int i = (1); i <= (5); ++i) {
    for (int j = (1); j <= (5); ++j) {
      scanf("%lld", &a[i][j]);
    }
  }
  vector<long long> vc;
  for (int i = (1); i <= (5); ++i) vc.push_back((long long)i);
  long long ans = 0LL;
  do
    ans = max(ans, (a[vc[0]][vc[1]] + a[vc[1]][vc[0]]) +
                       (a[vc[2]][vc[3]] + a[vc[3]][vc[2]]) +
                       (a[vc[1]][vc[2]] + a[vc[2]][vc[1]]) +
                       (a[vc[3]][vc[4]] + a[vc[4]][vc[3]]) +
                       (a[vc[2]][vc[3]] + a[vc[3]][vc[2]]) +
                       (a[vc[3]][vc[4]] + a[vc[4]][vc[3]]));
  while (next_permutation(vc.begin(), vc.end()));
  printf("%lld\n", ans);
  return 0;
}
