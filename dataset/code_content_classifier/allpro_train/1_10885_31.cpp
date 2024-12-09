#include <bits/stdc++.h>
using namespace std;
long long findGCD(long long a, long long b) {
  return ((b == 0) ? a : findGCD(b, a % b));
}
map<long long, long long> width;
long long wit = 0;
vector<pair<long long, long long> > rect[200005];
int main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = (1); i <= (n); i += (1)) {
    long long w, h, f;
    scanf("%lld %lld %lld", &h, &w, &f);
    if (width.find(w) == width.end()) {
      width[w] = ++wit;
    }
    rect[width[w]].push_back({h, f});
  }
  sort(rect[1].begin(), rect[1].end());
  for (long long i = (2); i <= (wit); i += (1)) {
    if (rect[i - 1].size() != rect[i].size()) {
      printf("0\n");
      return 0;
    }
    sort(rect[i].begin(), rect[i].end());
    for (long long j = (0); j <= ((long long)rect[i].size() - 1); j += (1)) {
      if (rect[i - 1][j].first != rect[i][j].first) {
        printf("0\n");
        return 0;
      }
    }
    long long gcd = findGCD(rect[i - 1][0].second, rect[i][0].second);
    long long n = rect[i - 1][0].second / gcd, dn = rect[i][0].second / gcd;
    for (long long j = (1); j <= ((long long)rect[i].size() - 1); j += (1)) {
      gcd = findGCD(rect[i - 1][j].second, rect[i][j].second);
      if (rect[i - 1][j].second / gcd != n || rect[i][j].second / dn != gcd) {
        printf("0\n");
        return 0;
      }
    }
  }
  long long tgcd = -1;
  for (long long j = (0); j <= ((long long)rect[1].size() - 1); j += (1)) {
    long long gcd = rect[1][j].second;
    for (long long i = (2); i <= (wit); i += (1)) {
      gcd = findGCD(gcd, rect[i][j].second);
    }
    if (tgcd == -1)
      tgcd = gcd;
    else
      tgcd = findGCD(tgcd, gcd);
  }
  long long ans = 0;
  for (long long i = (1); i <= (sqrt(tgcd)); i += (1)) {
    if (tgcd % i == 0) {
      if (tgcd == i * i)
        ans++;
      else
        ans += 2;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
