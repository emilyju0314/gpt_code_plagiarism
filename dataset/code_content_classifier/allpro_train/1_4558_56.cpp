#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const long long M = 1e18;
long long n, m, bty, inc, dmg;
int mx[N], reg[N];
vector<pair<long long, long long> > emy[N], cnt;
void find(long long mx, long long reg, long long H, long long T,
          long long nxt) {
  if (H > dmg) return;
  cnt.push_back({T, 1});
  if (reg == 0 || mx <= dmg) {
    if (~nxt) cnt.push_back({nxt, -1});
  } else {
    long long pt = (dmg - H + reg) / reg;
    if (~nxt)
      cnt.push_back({min(T + pt, nxt), -1});
    else
      cnt.push_back({T + pt, -1});
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> bty >> inc >> dmg;
  for (int i = (1); i <= (n); i++) {
    long long H;
    cin >> mx[i] >> H >> reg[i];
    emy[i].push_back({0, H});
  }
  for (int i = (1); i <= (m); i++) {
    long long T, E, H;
    cin >> T >> E >> H;
    emy[E].push_back({T, H});
  }
  for (int i = (1); i <= (n); i++) {
    sort((emy[i]).begin(), (emy[i]).end());
    for (int j = 0; j < (int)emy[i].size(); j++)
      find(mx[i], reg[i], emy[i][j].second, emy[i][j].first,
           (j + 1 == emy[i].size() ? -1 : emy[i][j + 1].first));
  }
  sort((cnt).begin(), (cnt).end());
  long long c = 0, ans = 0;
  for (int i = 0; i < ((int)cnt.size()); i++) {
    c += cnt[i].second;
    if (i + 1 != (int)cnt.size() && cnt[i].first != cnt[i + 1].first)
      ans = max(ans, c * (bty + inc * (cnt[i + 1].first - 1)));
  }
  if (c && inc)
    puts("-1");
  else
    cout << max(ans, c * bty) << endl;
}
