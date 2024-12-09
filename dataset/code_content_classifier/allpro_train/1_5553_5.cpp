#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5 + 1e4;
string t, s, S[MX];
int RA[MX], tRA[MX];
int SA[MX], tSA[MX];
int c[MX], n, m, q;
long long BEG[MX], END[MX];
long long BEG2[MX], END2[MX];
void countingSort(int k) {
  int maxi = max(300, n);
  for (int i = int(0); i < int(maxi); i++) c[i] = 0;
  for (int i = int(0); i < int(n); i++) c[i + k < n ? RA[i + k] : 0]++;
  for (int i = int(1); i < int(maxi); i++) c[i] += c[i - 1];
  for (int i = int(n - 1); i >= int(0); i--)
    tSA[--c[SA[i] + k < n ? RA[SA[i] + k] : 0]] = SA[i];
  for (int i = int(0); i < int(n); i++) SA[i] = tSA[i];
}
void constructSA() {
  for (int i = int(0); i < int(n); i++) RA[i] = t[i];
  for (int i = int(0); i < int(n); i++) SA[i] = i;
  for (int k = 1, r; k < n; k <<= 1) {
    countingSort(k);
    countingSort(0);
    tRA[SA[0]] = r = 0;
    for (int i = int(1); i < int(n); i++)
      tRA[SA[i]] =
          (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k])
              ? r
              : ++r;
    for (int i = int(0); i < int(n); i++) RA[i] = tRA[i];
    if (RA[SA[n - 1]] == n - 1) break;
  }
}
pair<int, int> stringMatching() {
  int lb = 0, ub = n - 1;
  while (lb < ub) {
    int mid = (lb + ub) / 2;
    if (strncmp(&t[0] + SA[mid], &s[0], m) >= 0)
      ub = mid;
    else
      lb = mid + 1;
  }
  if (strncmp(&t[0] + SA[lb], &s[0], m) != 0) return {-1, -1};
  pair<int, int> ans(lb, 0);
  lb = 0, ub = n - 1;
  while (lb < ub) {
    int mid = (lb + ub) / 2;
    if (strncmp(&t[0] + SA[mid], &s[0], m) > 0)
      ub = mid;
    else
      lb = mid + 1;
  }
  if (strncmp(&t[0] + SA[lb], &s[0], m) != 0) ub--;
  ans.second = ub;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  t.push_back('$');
  n = t.size();
  cin >> q;
  for (int i = int(0); i < int(q); i++) cin >> S[i];
  constructSA();
  for (int i = int(0); i < int(n); i++) BEG[i] = 0;
  for (int i = int(0); i < int(q); i++) {
    s = S[i];
    m = s.size();
    pair<int, int> p = stringMatching();
    if (p.first == -1) continue;
    BEG[p.first]++;
    BEG[p.second + 1]--;
  }
  for (int i = int(1); i < int(n); i++) BEG[i] += BEG[i - 1];
  for (int i = int(0); i < int(n); i++) BEG2[SA[i]] = BEG[i];
  reverse(t.begin(), --t.end());
  constructSA();
  for (int i = int(0); i < int(n); i++) END[i] = 0;
  for (int i = int(0); i < int(q); i++) {
    s = S[i];
    m = s.size();
    reverse(s.begin(), s.end());
    pair<int, int> p = stringMatching();
    if (p.first == -1) continue;
    END[p.first]++;
    END[p.second + 1]--;
  }
  for (int i = int(1); i < int(n); i++) END[i] += END[i - 1];
  for (int i = int(0); i < int(n); i++) END2[n - SA[i] - 1] = END[i];
  long long ans = 0;
  for (int i = int(0); i < int(n); i++) ans += BEG2[i] * END2[i];
  cout << ans << endl;
}
