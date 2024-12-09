#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MA = 1e6 + 5;
const long long MOD = 1e9 + 7;
long long c, n;
long long cnt[200010];
vector<pair<long long, long long> > coin;
long long lef[200010];
void read() {
  cin >> c >> n;
  long long k;
  for (long long i = 0; i < (n); i++) {
    cin >> k;
    cnt[k]++;
  }
  for (long long i = (1); i <= (c); i++) {
    if (cnt[i]) coin.push_back({i, cnt[i]});
  }
  int now = c;
  for (int i = ((long long)(coin).size()) - 1; i >= 0; i--) {
    lef[i] = now;
    now -= min(coin[i].second, now / coin[i].first) * coin[i].first;
  };
}
bool nd(int k) {
  pair<long long, long long> x;
  x.first = k;
  x.second = INF;
  vector<pair<long long, long long> >::iterator it =
      upper_bound(coin.begin(), coin.end(), x);
  ;
  if (it == coin.begin()) {
    return 1;
  }
  it--;
  if (lef[it - coin.begin()] < k) return 1;
  return 0;
}
bool che(int k) {
  if (nd(k)) return 0;
  int now = c - k;
  int d = ((long long)(coin).size()) - 1;
  while (d >= 0) {
    ;
    pair<long long, long long> x;
    x.first = now;
    x.second = INF;
    int i = upper_bound(coin.begin(), coin.end(), x) - coin.begin();
    if (i == 0) {
      break;
    }
    i--;
    i = min(i, d);
    now -= min(coin[i].second, now / coin[i].first) * coin[i].first;
    ;
    d = i - 1;
  }
  if (now) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  read();
  for (long long i = (1); i <= (c - 1); i++) {
    if (che(i)) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << "Greed is good\n";
  return 0;
}
