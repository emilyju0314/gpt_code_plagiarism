#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long mod = 1e9 + 7;
string s, t;
int32_t main() {
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    long long p[n];
    for (long long i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n, greater<long long>());
    long long x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;
    map<long long, long long> pos1;
    long long temp1 = a, temp2 = b;
    while (temp1 <= n) {
      pos1[temp1 - 1] += x;
      temp1 += a;
    }
    while (temp2 <= n) {
      pos1[temp2 - 1] += y;
      temp2 += b;
    }
    long long ans = 0;
    long long j = 0;
    long long ind = -1;
    long long max0 = x + y, max1 = max(x, y), max2 = min(x, y);
    multiset<long long, greater<long long>> s[3];
    for (long long i = 0; i < n; i++) {
      if (pos1.count(i)) {
        if (pos1[i] == max0) {
          if (s[1].size()) {
            if (!s[2].size() || p[j] >= *s[2].begin()) {
              long long temp = *s[1].begin();
              if (p[j] >= temp) {
                s[0].insert(p[j]);
                ans += max0 * (p[j++] / 100);
                continue;
              }
              ans -= max1 * (temp / 100);
              ans += max0 * (temp / 100);
              ans += max1 * (p[j] / 100);
              s[1].erase(s[1].begin());
              s[1].insert(p[j]);
              s[0].insert(temp);
              j++;
            } else {
              long long temp = *s[1].begin();
              long long temp2 = *s[2].begin();
              ans -= max1 * (temp / 100);
              ans += max0 * (temp / 100);
              ans += max2 * (p[j] / 100);
              ans += max1 * (temp2 / 100);
              ans -= max2 * (temp2 / 100);
              s[1].erase(s[1].begin());
              s[0].insert(temp);
              s[2].erase(s[2].begin());
              s[2].insert(p[j]);
              s[1].insert(temp2);
              j++;
            }
          } else if (s[2].size()) {
            long long temp = *s[2].begin();
            ans -= max2 * (temp / 100);
            ans += max0 * (temp / 100);
            ans += max2 * (p[j] / 100);
            s[2].erase(s[2].begin());
            s[2].insert(p[j]);
            s[0].insert(temp);
            j++;
          } else {
            ans += max0 * (p[j] / 100);
            s[0].insert(p[j]);
            j++;
          }
        } else if (pos1[i] == max1) {
          if (s[2].size()) {
            long long temp = *s[2].begin();
            ans -= max2 * (temp / 100);
            ans += max1 * (temp / 100);
            ans += max2 * (p[j] / 100);
            s[2].erase(s[2].begin());
            s[2].insert(p[j]);
            s[1].insert(temp);
            j++;
          } else {
            ans += max1 * (p[j] / 100);
            s[1].insert(p[j]);
            j++;
          }
        } else {
          ans += max2 * (p[j] / 100);
          s[2].insert(p[j]);
          j++;
        }
      }
      if (ans >= k) {
        ind = i + 1;
        break;
      }
    }
    cout << ind << '\n';
  }
  return 0;
}
