#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, k, f;
  cin >> n >> a >> b >> k >> f;
  vector<string> ss(n), es(n);
  map<pair<string, string>, long> m;
  for (int i = 0; i < n; i++) {
    cin >> ss[i] >> es[i];
    if (m.find(make_pair(min(ss[i], es[i]), max(ss[i], es[i]))) == m.end()) {
      m[make_pair(min(ss[i], es[i]), max(ss[i], es[i]))] = 0;
    }
    if (i != 0 && ss[i] == es[i - 1])
      m[make_pair(min(ss[i], es[i]), max(ss[i], es[i]))] += b;
    else
      m[make_pair(min(ss[i], es[i]), max(ss[i], es[i]))] += a;
  }
  map<pair<string, string>, long>::iterator mit;
  vector<long> arr;
  long long ans = 0;
  for (mit = m.begin(); mit != m.end(); mit++) {
    arr.push_back(mit->second);
    ans += mit->second;
  }
  sort(arr.begin(), arr.end());
  for (long i = arr.size() - 1; i >= 0 && k > 0 && arr[i] > f; i--, k--) {
    ans -= arr[i];
    ans += f;
  }
  cout << ans << endl;
  return 0;
}
