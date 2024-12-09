#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  scanf("%d", &N);
  vector<long long> dat(N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &dat[i]);
  }
  sort((dat).begin(), (dat).end());
  int cnt[64];
  memset((cnt), 0, sizeof(cnt));
  long long ans = 0;
  int take = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      for (int k = j; k < N; ++k) {
        ans = max(ans, dat[i] | dat[j] | dat[k]);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
