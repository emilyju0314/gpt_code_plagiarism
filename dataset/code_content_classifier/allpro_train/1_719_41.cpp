#include <bits/stdc++.h>
using namespace std;
int n, m;
string ans, s;
vector<long long> seconds;
vector<string> hopes;
long long months[13] = {0,   0,   31,  60,  91,  121, 152,
                        182, 213, 244, 274, 305, 335};
int main() {
  cin >> n >> m;
  int l = 0;
  getline(cin, s);
  while (getline(cin, s)) {
    long long times = 0;
    times = (s[5] - '0') * 10 + s[6] - '0';
    times = months[times] + (s[8] - '0') * 10 + s[9] - '0';
    times = times * 24 + (s[11] - '0') * 10 + s[12] - '0';
    times = times * 60 + (s[14] - '0') * 10 + s[15] - '0';
    times = times * 60 + (s[17] - '0') * 10 + s[18] - '0';
    seconds.push_back(times);
    hopes.push_back(s.substr(0, 19));
  }
  for (int i = m - 1; i < seconds.size(); i++) {
    int be = i - m + 1;
    if (seconds[be] + n - 1 >= seconds[i]) {
      cout << hopes[i];
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
