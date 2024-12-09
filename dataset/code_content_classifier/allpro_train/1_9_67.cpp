#include <bits/stdc++.h>
using namespace std;
vector<int> srr;
map<int, int> occ;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int arr[200], n, m, pj, k, fast = 1, last;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    srr.push_back(arr[i]);
  }
  sort(srr.begin(), srr.end(), greater<int>());
  cin >> m;
  last = n;
  while (m--) {
    vector<int> vec;
    cin >> k >> pj;
    for (int i = 0; i < k; ++i) vec.push_back(srr[i]);
    vector<int> ans;
    sort(vec.begin(), vec.end());
    fast = 1;
    for (int s = 1; s <= k; ++s) {
      for (int i = 0; i < k; ++i) {
        if (vec[i] != -1) {
          for (int j = fast; j <= last; ++j) {
            if (arr[j] == vec[i]) {
              occ.clear();
              for (int p = 0; p < k; ++p) {
                if (vec[p] != -1) occ[vec[p]]++;
              }
              for (int p = j; p <= last; ++p) {
                if (occ[arr[p]]) occ[arr[p]]--;
              }
              bool pos = true;
              for (int p = 0; p < k && pos; ++p)
                if (vec[p] > 0 && occ[vec[p]] > 0) pos = false;
              if (pos) fast = j + 1;
              if (pos) {
                ans.push_back(vec[i]);
                vec[i] = -1;
                i = k;
              }
              break;
            }
          }
        }
      }
    }
    cout << ans[pj - 1] << endl;
  }
  return 0;
}
