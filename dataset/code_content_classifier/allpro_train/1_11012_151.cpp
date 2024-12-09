#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const int mod = 1000000000 + 7;
const int N = 1000000 + 6;
const int maxn = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  map<string, int> m;
  for (int i = 0; i < n; i++) m[s[i]] = i;
  sort(s, s + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      string t = "";
      bool bo = true;
      for (int z = 0; z < k; z++) {
        if (s[i][z] == s[j][z]) {
          t += s[i][z];
        } else {
          int temp = s[i][z] + s[j][z];
          t += 'S' + 'E' + 'T' - temp;
        }
      }
      if (bo) {
        int temp = lower_bound(s + j + 1, s + n, t) - s;
        if (s[temp] == t) ans++;
      }
    }
  }
  cout << ans;
}
