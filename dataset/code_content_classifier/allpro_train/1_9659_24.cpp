#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9, mod = 1e9 + 7, inf = 1e17;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  long long arr[100005];
  map<int, int> freq;
  cin >> n;
  map<int, pair<int, int>> m;
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
    if (!s.count(arr[i])) m[arr[i]].first = i + 1;
    m[arr[i]].second = i + 1;
    s.insert(arr[i]);
  }
  int min = 1e8, l = -1, r = -1, max = -1;
  for (auto el : s) {
    if (freq[el] >= max) {
      if (freq[el] == max) {
        if ((m[el].second - m[el].first) < min) {
          min = (m[el].second - m[el].first);
          l = m[el].first;
          r = m[el].second;
        }
      } else {
        min = (m[el].second - m[el].first);
        l = m[el].first;
        r = m[el].second;
      }
      max = freq[el];
    }
  }
  cout << l << " " << r;
}
