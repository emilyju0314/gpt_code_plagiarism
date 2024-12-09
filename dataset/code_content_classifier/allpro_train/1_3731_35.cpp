#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int mod = 1000000007;
int n, m;
long long anscnt[maxn];
long long anscum[maxn];
vector<long long> subjectrank[maxn];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    long long s, r;
    scanf("%lld %lld", &s, &r);
    subjectrank[s].push_back(r);
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    sort(subjectrank[i].rbegin(), subjectrank[i].rend());
    for (int j = 0; j < subjectrank[i].size(); j++) {
      long long v = subjectrank[i][j];
      anscum[j + 1] = 0;
      anscum[j + 1] += anscum[j] + v;
      if (anscum[j + 1] >= 0) anscnt[j + 1] += anscum[j + 1];
    }
  }
  for (int i = 0; i < maxn; i++) ans = max(ans, anscnt[i]);
  printf("%lld\n", ans);
}
