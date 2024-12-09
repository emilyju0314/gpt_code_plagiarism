#include <bits/stdc++.h>
using namespace std;
long long in() {
  long long a;
  scanf("%lld", &a);
  return a;
}
double din() {
  double a;
  scanf("%lf", &a);
  return a;
}
long long bigmod(long long b, long long p, long long md) {
  if (p == 0) return 1;
  if (p % 2 == 1) {
    return ((b % md) * bigmod(b, p - 1, md)) % md;
  } else {
    long long y = bigmod(b, p / 2, md);
    return (y * y) % md;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long getRandom(long long a, long long b) {
  long long ret = (long long)rand() * (long long)rand();
  ret %= (b - a + 1);
  ret += a;
  return ret;
}
int freq[100005], ffreq[100005];
int main() {
  int n = in();
  int ar[n + 5];
  for (int i = 0; i < n; i++) {
    ar[i] = in();
  }
  set<int> st;
  int ans = min(2, n);
  for (int i = 0; i < n; i++) {
    if (ffreq[freq[ar[i]]] == 1) st.erase(freq[ar[i]]);
    if (ffreq[freq[ar[i]]]) ffreq[freq[ar[i]]]--;
    freq[ar[i]]++;
    ffreq[freq[ar[i]]]++;
    if (ffreq[freq[ar[i]]] == 1) st.insert(freq[ar[i]]);
    if (st.size() == 2) {
      if (ffreq[1] == 1)
        ans = max(ans, i + 1);
      else {
        set<int>::iterator it = st.begin();
        int xx = *it;
        it++;
        int yy = *it;
        if (yy == xx + 1 && ffreq[yy] == 1) ans = max(ans, i + 1);
      }
    } else if (st.size() == 1 && *st.begin() == 1)
      ans = max(ans, i + 1);
    else if (st.size() == 1 && ffreq[*st.begin()] == 1)
      ans = max(ans, i + 1);
  }
  printf("%lld\n", (long long)ans);
}
