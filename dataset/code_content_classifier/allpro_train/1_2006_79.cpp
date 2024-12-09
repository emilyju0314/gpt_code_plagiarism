#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  for (int z = 0; z < q; z++) {
    int n;
    cin >> n;
    int ans = 0;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].first;
      v[i].second = i;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) {
      vector<int> nb;
      for (int j = 0; j < 10; j++) nb.push_back(j);
      int p = i;
      while (v[i].first == v[p - 1].first && i < n) {
        ans++;
        int a = (v[i].first / 10) * 10;
        for (int j = 0; j < n; j++) {
          if (j == i) continue;
          int b = (v[j].first / 10) * 10;
          if (a == b) {
            int c = v[j].first % 10;
            nb[c] = -1;
          }
        }
        for (int j = 0; j < 10; j++) {
          if (nb[j] != -1) {
            v[i].first -= (v[i].first % 10);
            v[i].first += j;
            break;
          }
        }
        i++;
      }
    }
    int g = 1000;
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
      int f = v[i].first;
      v[i].first = v[i].second;
      v[i].second = f;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
      while (v[i].second / g == 0 && g != 1) {
        cout << '0';
        g /= 10;
      }
      g = 1000;
      cout << v[i].second << "\n";
    }
  }
}
