#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b) {
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = (r * a);
    a = (a * a);
    b >>= 1;
  }
  return r;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first)
    return (a.second > b.second);
  else if (a.second == b.second)
    return (a.first < b.first);
  else
    return (a.first < b.first);
}
long long rootf(long long k, long long arr[]) {
  while (arr[k] != k) {
    arr[k] = arr[arr[k]];
    k = arr[k];
  }
  return k;
}
bool find(long long arr[], long long k, long long l) {
  if (rootf(k, arr) == rootf(l, arr))
    return true;
  else
    return false;
}
void unionf(long long arr[], long long size[], long long n, long long k,
            long long l) {
  long long rk = rootf(k, arr);
  long long rl = rootf(l, arr);
  if (rl == rk) return;
  if (size[rk] < size[rl]) {
    arr[rk] = arr[rl];
    size[rl] += size[rk];
  } else {
    arr[rl] = arr[rk];
    size[rk] += size[rl];
  }
}
map<string, vector<string> > m1;
int dfs(string s, int cnt) {
  int ct = cnt;
  for (long long i = 0; i < m1[s].size(); i++) {
    cnt = max(cnt, dfs(m1[s][i], ct) + 1);
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i, j, k, l, m, n;
  cin >> n;
  for (i = 0; i < n; i++) {
    string a, b, c;
    cin >> a >> b >> c;
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    transform(c.begin(), c.end(), c.begin(), ::toupper);
    m1[c].push_back(a);
  }
  int ans = dfs("POLYCARP", 1);
  cout << ans << endl;
}
