#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 1000 + 5;
int ans[maxn], c[maxn];
map<pair<int, int>, int> num;
map<int, int> tedad;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    c[i] = a;
    tedad[a]++;
    if (tedad[a] != 1) {
      num.erase(make_pair(tedad[a] - 1, a));
    }
    num[make_pair(tedad[a], a)] = a;
  }
  auto it = num.lower_bound(make_pair(2, -1000000000 - 8));
  if (it != num.begin()) {
    it--;
    ans[0] = it->second;
  } else {
    ans[0] = -1;
  }
  int p = 1;
  for (int i = k; i < n; i++) {
    int b;
    cin >> b;
    c[i] = b;
    num.erase(make_pair(tedad[c[p - 1]], c[p - 1]));
    tedad[c[p - 1]]--;
    if (tedad[c[p - 1]] > 0) {
      num[make_pair(tedad[c[p - 1]], c[p - 1])] = c[p - 1];
    }
    tedad[b]++;
    if (tedad[b] != 1) {
      num.erase(make_pair(tedad[b] - 1, b));
    }
    num[make_pair(tedad[b], b)] = b;
    auto it = num.lower_bound(make_pair(2, -1000000000 - 8));
    if (it != num.begin()) {
      it--;
      ans[p] = it->second;
    } else {
      ans[p] = -1;
    }
    p++;
  }
  for (int i = 0; i < n - k + 1; i++) {
    if (ans[i] == -1) {
      cout << "Nothing" << endl;
    } else {
      cout << ans[i] << endl;
    }
  }
}
