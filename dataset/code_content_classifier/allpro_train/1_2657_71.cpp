#include <bits/stdc++.h>
using namespace std;
bool operator<(pair<long long int, long long int>& p1,
               pair<long long int, long long int>& p2) {
  if (p1.first != p2.first) {
    return p1.first > p2.first;
  } else {
    return p1.second > p2.second;
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int>> time;
  vector<long long int> minutes;
  for (long long int i = 0; i < n; i++) {
    string t;
    cin >> t;
    long long int hh = (t[0] - '0') * 10 + (t[1] - '0');
    long long int mm = (t[3] - '0') * 10 + (t[4] - '0');
    minutes.push_back((hh * 60) + mm);
    time.push_back({hh, mm});
  }
  sort(minutes.begin(), minutes.end());
  sort(time.begin(), time.end());
  long long int ans = 0;
  for (long long int i = 1; i < n; i++) {
    if (minutes[i] == minutes[i - 1]) continue;
    ans = max(ans, minutes[i] - minutes[i - 1] - 1);
  }
  ans = max(ans, ((24 * 60) - minutes[n - 1] + minutes[0] - 1));
  string answer = to_string(ans / 60);
  if (answer.size() == 1) {
    answer = "0" + answer;
  }
  answer += ":";
  if ((ans % 60) < 10) {
    answer += "0";
  }
  answer += to_string(ans % 60);
  cout << answer << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
