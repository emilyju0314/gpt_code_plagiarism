#include <bits/stdc++.h>
using namespace std;
long long N, S;
vector<pair<long long, pair<long long, long long>>> fava;
vector<pair<long long, pair<long long, long long>>> favb;
long long pa = 0, pb = 0;
long long ans = 0;
int main() {
  cin >> N >> S;
  long long s, a, b;
  for (int i = 0; i < N; ++i) {
    cin >> s >> a >> b;
    if (a >= b) {
      fava.push_back({a, {s, b}});
      pa += s;
    } else {
      favb.push_back({b, {s, a}});
      pb += s;
    }
  }
  sort(fava.begin(), fava.end());
  sort(favb.begin(), favb.end());
  for (int i = 0; i < fava.size(); ++i) {
    ans += fava.at(i).first * fava.at(i).second.first;
  }
  for (int i = 0; i < favb.size(); ++i) {
    ans += favb.at(i).first * favb.at(i).second.first;
  }
  if (pa % S + pb % S <= S) {
    for (int i = 0; i < fava.size(); ++i) {
      fava.at(i).first = fava.at(i).first - fava.at(i).second.second;
    }
    for (int i = 0; i < favb.size(); ++i) {
      favb.at(i).first = favb.at(i).first - favb.at(i).second.second;
    }
    sort(fava.begin(), fava.end());
    sort(favb.begin(), favb.end());
    long long res[2] = {0};
    long long count = 0;
    for (int i = 0; i < fava.size(); ++i) {
      count += fava.at(i).second.first;
      if (count >= pa % S) {
        res[0] += (fava.at(i).second.first - count + pa % S) * fava.at(i).first;
        break;
      }
      res[0] += fava.at(i).second.first * fava.at(i).first;
    }
    count = 0;
    for (int i = 0; i < favb.size(); ++i) {
      count += favb.at(i).second.first;
      if (count >= pb % S) {
        res[1] += (favb.at(i).second.first - count + pb % S) * favb.at(i).first;
        break;
      }
      res[1] += favb.at(i).second.first * favb.at(i).first;
    }
    cout << max(ans - res[0], ans - res[1]) << endl;
  } else
    cout << ans << endl;
  return 0;
}
