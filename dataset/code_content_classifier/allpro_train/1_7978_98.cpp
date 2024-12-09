#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int n;
vector<pair<int, int> > v;
long long int fat[300300];
long long int freq[300300], freq2[300300];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  fat[0] = 1ll;
  fat[1] = 1ll;
  for (long long int i = 2; i < 300300; i++) fat[i] = (i * fat[i - 1]) % MOD;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
    freq[a]++;
    freq2[b]++;
  }
  long long int badfirst = 1;
  for (int i = 1; i <= 300000; i++) badfirst = (badfirst * fat[freq[i]]) % MOD;
  long long int badsecond = 1;
  for (int i = 1; i <= 300000; i++)
    badsecond = (badsecond * fat[freq2[i]]) % MOD;
  sort(v.begin(), v.end());
  long long int badboth = 1;
  for (int i = 1; i < n; i++)
    if (v[i].second < v[i - 1].second) badboth = 0;
  map<pair<int, int>, int> table;
  for (auto x : v) table[x]++;
  for (auto x : table) badboth = (badboth * fat[x.second]) % MOD;
  long long int ans = (fat[n] + badboth - badfirst - badsecond) % MOD;
  ans = (ans + MOD) % MOD;
  cout << ans << endl;
}
