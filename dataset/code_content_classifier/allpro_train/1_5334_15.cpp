#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
vector<string> v = {"Anka",   "Chapay", "Cleo",       "Troll",
                    "Dracul", "Snowy",  "Hexadecimal"};
map<string, long long> mp;
bool like[10][10];
long long gett(vector<long long> &perm, long long a, long long b) {
  long long bty = 0;
  for (long long i = 0; i < a + 1; i++)
    for (long long j = 0; j < a + 1; j++)
      if (like[perm[i]][perm[j]]) bty++;
  for (long long i = a + 1; i < b + 1; i++)
    for (long long j = a + 1; j < b + 1; j++)
      if (like[perm[i]][perm[j]]) bty++;
  for (long long i = b + 1; i < 7; i++)
    for (long long j = b + 1; j < 7; j++)
      if (like[perm[i]][perm[j]]) bty++;
  return bty;
}
void solve() {
  for (long long i = 0; i < v.size(); i++) mp[v[i]] = i;
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    string a, b, c;
    cin >> a >> b >> c;
    like[mp[a]][mp[c]] = true;
  }
  vector<long long> b(3);
  cin >> b[0] >> b[1] >> b[2];
  sort(b.rbegin(), b.rend());
  long long beauty = 0, diff = LLONG_MAX;
  vector<long long> perm(7);
  iota(perm.begin(), perm.end(), 0);
  do {
    for (long long i = 0; i < 7; i++)
      for (long long j = i + 1; j + 1 < 7; j++) {
        long long a = b[0] / (i + 1), y = b[1] / (j - i), c = b[2] / (6 - j);
        long long df = max({a, y, c}) - min({a, y, c});
        if (df < diff) {
          diff = df;
          beauty = gett(perm, i, j);
        } else if (df == diff) {
          beauty = max(beauty, gett(perm, i, j));
        }
      }
  } while (next_permutation(perm.begin(), perm.end()));
  cout << diff << " " << beauty << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
