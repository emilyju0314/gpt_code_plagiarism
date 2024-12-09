#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  long long previous = 0;
  vector<long long> preb;
  vector<long long> prea;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'b') {
      preb.emplace_back(previous);
      previous = 0;
    } else
      previous++;
  }
  preb.emplace_back(previous);
  previous = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'a') {
      prea.emplace_back(previous);
      previous = 0;
    } else
      previous++;
  }
  prea.emplace_back(previous);
  long long countb = 0;
  long long counta = 0;
  long long res = 0;
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'b') {
      countb++;
      if (countb == k + 1) {
        res = max(res, counta + k);
        countb--;
        counta -= preb[c];
        c++;
      }
    } else
      counta++;
  }
  res = max(res, counta + countb);
  countb = 0;
  counta = 0;
  c = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'a') {
      counta++;
      if (counta == k + 1) {
        res = max(res, countb + k);
        counta--;
        countb -= prea[c];
        c++;
      }
    } else
      countb++;
  }
  res = max(res, counta + countb);
  cout << res << '\n';
}
