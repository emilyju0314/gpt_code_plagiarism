#include <bits/stdc++.h>
using namespace std;
const int MAX = 5002;
int cnt3[MAX];
int cnt2[MAX];
int arr[MAX]{0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<pair<int, int>> v;
  cnt3[0] = 0;
  cnt2[0] = 0;
  int n;
  cin >> n;
  int q;
  cin >> q;
  int sum = 0;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    v.push_back({l, r});
    arr[l]++;
    arr[r + 1]--;
  }
  int val = 0;
  for (int i = 1; i <= n; i++) {
    val += arr[i];
    if (val > 0) sum += 1;
    if (val < 3)
      cnt3[i] = 1 + cnt3[i - 1];
    else
      cnt3[i] = cnt3[i - 1];
    if (val < 2)
      cnt2[i] = 1 + cnt2[i - 1];
    else
      cnt2[i] = cnt2[i - 1];
  }
  sort(v.begin(), v.end());
  int best = INT_MAX;
  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = i + 1; j < v.size(); j++) {
      int temp = 0;
      if (v[i].first <= v[j].first && v[j].first <= v[i].second) {
        int l = v[j].first;
        int r = min(v[i].second, v[j].second);
        int maxr = max(v[i].second, v[j].second);
        temp += (cnt3[r] - cnt3[l - 1]);
        temp += (cnt2[l - 1] - cnt2[v[i].first - 1]);
        temp += (cnt2[maxr] - cnt2[r]);
      } else {
        temp += (cnt2[v[i].second] - cnt2[v[i].first - 1]);
        temp += (cnt2[v[j].second] - cnt2[v[j].first - 1]);
      }
      best = min(best, temp);
    }
  }
  cout << sum - best << endl;
  return 0;
}
