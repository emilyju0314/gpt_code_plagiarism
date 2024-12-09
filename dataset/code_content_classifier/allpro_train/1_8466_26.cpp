#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

long long n, k, cnt = 0;
vector<pair<long long, long long>> s;
long long num[100005] = {0};

long long solve();

int main() {
  cin >> n >> k;
  for(long long i = 0; i < n; ++i) {
    long long t, d;
    cin >> t >> d;
    --t;
    s.push_back(make_pair(d, t));
  }
  sort(s.begin(), s.end(),
       greater<pair<long long, long long>>());
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long now = 0, ans = 0, r = k - 1;
  for(long long i = 0; i < k; ++i) {
    now += s[i].fi;
    if(++num[s[i].se] == 1) ++cnt;
  }
  ans = now + cnt * cnt;
  for(long long i = k; i < n; ++i)
    if(num[s[i].se] == 0) {
      while(r >= 0 && num[s[r].se] == 1) --r;
      if(r < 0) break;
      now += s[i].fi - s[r].fi;
      ++cnt;
      ++num[s[i].se];
      --num[s[r].se];
      --r;
      ans = max(ans, now + cnt * cnt);
    }
  return ans;
}