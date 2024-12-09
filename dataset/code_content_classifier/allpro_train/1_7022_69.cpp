#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long p1 = 1000000007;
long long power(long long x, long long y) {
  long long ans = 1;
  x = x % p1;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % p1;
    y = y >> 1;
    x = (x * x) % p1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long tot1 = 0, tot2 = 0, cnt1 = 0, cnt2 = 0;
  for (long long i = 0; i < n; i++) {
    if (i < n / 2) {
      if (s[i] == '?')
        cnt1++;
      else
        tot1 += (s[i] - '0');
    } else {
      if (s[i] == '?')
        cnt2++;
      else
        tot2 += (s[i] - '0');
    }
  }
  if (tot1 == tot2 && cnt1 == cnt2) {
    cout << "Bicarp";
    return 0;
  }
  if (cnt1 == cnt2 && tot1 != tot2) {
    cout << "Monocarp";
    return 0;
  }
  if (cnt1 < cnt2) {
    swap(cnt1, cnt2);
    swap(tot1, tot2);
  }
  for (long long i = 0; i < cnt1 - cnt2; i++) {
    if (i % 2 == 0) {
      if (tot1 + 9 >= tot2) tot1 += 9;
    } else {
      if (tot1 < tot2) tot1 += min((long long)9, tot2 - tot1);
    }
  }
  if (tot1 == tot2)
    cout << "Bicarp";
  else
    cout << "Monocarp";
}
