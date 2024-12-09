#include <bits/stdc++.h>
using namespace std;
const long long LIM = 1e5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(10);
  cout << fixed;
  long long n, r;
  cin >> n >> r;
  vector<long long> L(n);
  vector<long long> T(n);
  for (long long i = 0; i < n; i++) cin >> L[i];
  for (long long i = 0; i < n; i++) cin >> T[i];
  long long cnt = 0;
  vector<long long> ans;
  long long curTime = 0;
  long long timePotion = 0;
  for (long long i = 0; i < n; i++) {
    long long l = L[i];
    long long t = T[i];
    if (timePotion < l) {
      t -= timePotion;
      l -= timePotion;
      curTime += timePotion;
      if (t < 0) {
        cout << -1 << "\n";
        return 0;
      }
      if (2 * l > t) {
        long long szz = ans.size();
        long long timeNeedPotion = 2 * l - t;
        if (t - timeNeedPotion < 0) {
          cout << -1 << "\n";
          return 0;
        }
        long long cntMoments = (timeNeedPotion / r) + (timeNeedPotion % r != 0);
        curTime = curTime + t - timeNeedPotion;
        cnt += cntMoments;
        for (long long i = 0; i < cntMoments; i++) {
          if (ans.size() < LIM) {
            ans.push_back(curTime + i * r);
          } else {
            break;
          }
        }
        curTime += timeNeedPotion;
        timePotion = r - (timeNeedPotion % r);
        if (timePotion == r) timePotion -= r;
      } else {
        curTime += l * 2;
        timePotion = 0;
      }
    } else {
      if (l > t) {
        cout << -1 << "\n";
        return 0;
      } else {
        timePotion -= l;
        curTime += l;
      }
    }
  }
  cout << cnt << "\n";
  if (cnt <= LIM) {
    for (long long xx : ans) cout << xx << " ";
    cout << "\n";
  }
  return 0;
}
