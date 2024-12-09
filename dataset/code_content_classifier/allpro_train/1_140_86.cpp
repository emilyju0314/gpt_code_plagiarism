#include <bits/stdc++.h>
using namespace std;
const int N = (long long)1e6 + 1;
const int inf = (long long)1e9 + 1;
long long n, mx;
string s, mxs;
map<string, long long> mp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for (long long i = 0; i < s.size() - 1; i++) {
    string t;
    t += s[i];
    t += s[i + 1];
    mp[t]++;
    if (mp[t] > mx) {
      mx = mp[t];
      mxs = t;
    }
  }
  cout << mxs;
  return 0;
}
