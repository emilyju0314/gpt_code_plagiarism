#include <bits/stdc++.h>
using namespace std;
int ile[1000005];
int best[1000005];
vector<int> primes;
void sito() {
  primes.push_back(2);
  for (int i = 3; i <= 1000005; i += 2) {
    bool ok = true;
    for (int j = (0); j < (primes.size()); ++j) {
      if (i % primes[j] == 0) {
        ok = false;
        break;
      }
      if (primes[j] * primes[j] > i) break;
    }
    if (ok) primes.push_back(i);
  }
}
int main() {
  sito();
  int(n);
  scanf("%d", &(n));
  ;
  vector<int> v;
  for (int i = (0); i < (n); ++i) {
    int(a);
    scanf("%d", &(a));
    ;
    v.push_back(a);
  }
  for (int i = (0); i < (1000005); ++i) ile[i] = 0;
  for (int i = (0); i < (n); ++i) ile[v[i]]++;
  best[0] = 0;
  for (int i = (1); i < (1000005); ++i) {
    best[i] = (ile[i]) + (i == 1 ? 0 : best[1]);
    for (int j = (0); j < (primes.size()); ++j) {
      if (i == primes[j]) {
        best[i] = ile[1] + ile[i];
      } else if (i % primes[j] == 0) {
        best[i] = max(best[i], ile[i] + best[i / primes[j]]);
        best[i] = max(best[i], ile[i] + best[primes[j]]);
      }
      if (primes[j] * primes[j] > i) break;
    }
  }
  int ans = 0;
  for (int i = (0); i < (n); ++i) ans = max(ans, best[v[i]]);
  printf("%d\n", ans);
}
