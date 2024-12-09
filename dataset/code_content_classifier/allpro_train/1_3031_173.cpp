#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll INF_LL = (ll)1e18;
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), mp[a[i]]++;
    set<int> v;
    bool flag = false;
    for (auto& i : mp) {
      if (i.second >= 2) v.insert(i.first);
      if (i.second >= 4) {
        flag = true;
        printf("%d %d %d %d\n", i.first, i.first, i.first, i.first);
        break;
      }
    }
    if (flag) continue;
    double min = INF;
    auto fi = v.begin();
    auto li = fi;
    li++;
    int ansa = -1, ansb = -1;
    while (li != v.end()) {
      if ((double(*li) / *fi + *fi / *li) < min) {
        min = double(*li) / *fi + *fi / *li;
        ansa = *li;
        ansb = *fi;
      }
      fi++;
      li++;
    }
    printf("%d %d %d %d\n", ansa, ansa, ansb, ansb);
  }
  return 0;
}
