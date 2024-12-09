#include <bits/stdc++.h>
using namespace std;
using P = pair<long long, long long>;

long long n;
vector<long long> a, cnt;

long long solve();
long long dfs(long long s, long long nextid, long long sum);

int main() {
  cin >> n;
  a.resize(n);
  cnt.assign(n, 0);
  for(int i = 0; i < n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0;
  for(int i = 0; i < n; ++i) res += a[i];
  return res - dfs(0, 0, 0);
}

long long dfs(long long s, long long nextid,
              long long sum) {
  if(nextid == (1LL << n)) return sum;
  long long res = sum;
  P nowp = make_pair(s, nextid);
  // nextid:false
  res = max(res, dfs(s, nextid + 1, sum));
  // nextid:true
  vector<int> lst;
  for(int i = 0; i < n; ++i)
    if(nextid >> i & 1) lst.push_back(i);
  int lstsize = lst.size();
  if(lstsize <= 1) return res;
  for(int i = 0; i < lstsize; ++i)
    for(int j = i + 1; j < lstsize; ++j) {
      if(s >> (lst[i] * n + lst[j]) & 1) return res;
      s += (1LL << (lst[i] * n + lst[j]));
    }
  for(int i = 0; i < lstsize; ++i) {
    if(++cnt[lst[i]] > a[lst[i]]) {
      for(int j = i; j >= 0; --j) --cnt[lst[j]];
      return res;
    }
  }
  sum += lstsize - 1;
  nowp = make_pair(s, nextid);
  res = max(res, dfs(s, nextid + 1, sum));
  for(int i = 0; i < lstsize; ++i) --cnt[lst[i]];
  return res;
}
