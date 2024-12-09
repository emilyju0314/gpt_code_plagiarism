#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
set<int> possible[102];
string users[102], message[102];
int t, n, m, memo[102][102], result[102], cache[102][102];
int dp(int idx, int last) {
  if (idx == m + 1) {
    return 1;
  }
  int &ret = memo[idx][last];
  if (ret != -1) {
    return ret;
  }
  ret = 0;
  for (auto i : possible[idx]) {
    if (i != last && dp(idx + 1, i) == 1) {
      ret = 1;
      cache[idx][last] = i;
      break;
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    mp.clear();
    for (int i = 1; i <= n; i++) {
      cin >> users[i];
      mp[users[i]] = i;
    }
    cin >> m;
    string line;
    getline(cin, line);
    for (int i = 1; i <= m; i++) {
      possible[i].clear();
      for (int j = 1; j <= n; j++) {
        possible[i].insert(j);
      }
    }
    for (int i = 1; i <= m; i++) {
      getline(cin, line);
      int p = line.find(':');
      if (line[0] != '?') {
        string username = line.substr(0, p);
        possible[i].clear();
        possible[i].insert(mp[username]);
        possible[i - 1].erase(mp[username]);
        possible[i + 1].erase(mp[username]);
      }
      line = line.substr(p + 1);
      message[i] = line;
      for (int j = 0; j < line.length(); j++) {
        if (line[j] == '.' || line[j] == ',' || line[j] == '?' ||
            line[j] == '!') {
          line[j] = ' ';
        }
      }
      vector<string> temp;
      string tmp;
      stringstream ss(line);
      while (getline(ss, tmp, ' ')) {
        temp.push_back(tmp);
      }
      for (int j = 0; j < temp.size(); j++) {
        possible[i].erase(mp[temp[j]]);
      }
    }
    memset(memo, -1, sizeof(memo));
    if (dp(1, 0) == 0) {
      cout << "Impossible" << endl;
      continue;
    }
    int cur = 1, last = 0;
    while (cur <= m) {
      result[cur] = cache[cur][last];
      last = result[cur];
      cur++;
    }
    for (int i = 1; i <= m; i++) {
      cout << users[result[i]] << ":" << message[i] << endl;
    }
  }
  return 0;
}
