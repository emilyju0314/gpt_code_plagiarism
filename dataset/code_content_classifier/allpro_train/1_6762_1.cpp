#include <bits/stdc++.h>
using namespace std;
const int N = 2750131;
const int INF = 1e9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
int d[400000 + 314], isNonPrime[N + 1];
vector<int> pr;
void primegen() {
  pr.push_back(0);
  for (int i = 2; i <= N; ++i) {
    if (!isNonPrime[i]) {
      if (1ll * i * i <= N) {
        for (int j = i * i; j <= N; j += i) {
          isNonPrime[j] = 1;
        }
      }
      pr.push_back(i);
    }
  }
}
int main() {
  primegen();
  int n = 0;
  map<int, int> mp;
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    cin >> d[i];
    mp[d[i]]++;
  }
  int cnt = 0;
  sort(d, d + 2 * n);
  for (int i = 2 * n - 1; i >= 0; --i) {
    if (d[i] >= 2 && d[i] <= 2e5)
      if (mp[d[i]])
        if (isNonPrime[d[i]] == 0 && mp[pr[d[i]]]) {
          cout << d[i] << " ";
          mp[pr[d[i]]]--;
          mp[d[i]]--;
          cnt++;
          if (cnt == n) return 0;
        } else {
          int maxi = -INF;
          int it = 1;
          while (it * it <= d[i]) {
            if (d[i] % it == 0) {
              maxi = max(maxi, it);
              if (it != 1) maxi = max(maxi, d[i] / it);
            }
            it++;
          }
          if (mp[maxi]) {
            cout << d[i] << " ";
            mp[maxi]--;
            mp[d[i]]--;
            cnt++;
            if (cnt == n) return 0;
          }
        }
  }
}
