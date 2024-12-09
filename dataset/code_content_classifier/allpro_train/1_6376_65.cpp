#include <bits/stdc++.h>
using namespace std;
map<string, map<string, int> > mapp;
map<string, vector<string> > last;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  string s, num, temp = "";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> m;
    for (int i = 0; i < m; i++) {
      cin >> num;
      temp = "";
      last[s].push_back(num);
      for (int i = num.size() - 1; i >= 0; i--) {
        reverse(temp.begin(), temp.end());
        temp += num[i];
        reverse(temp.begin(), temp.end());
        mapp[s][temp]++;
      }
    }
  }
  cout << mapp.size() << endl;
  for (auto it = mapp.begin(); it != mapp.end(); it++) {
    s = it->first;
    cout << s << " ";
    sort(last[s].begin(), last[s].end());
    vector<string> ans;
    for (int i = 0; i < last[s].size(); i++) {
      string x = last[s][i];
      if (mapp[s][x] > 1)
        mapp[s][x]--;
      else
        ans.push_back(last[s][i]);
    }
    cout << ans.size() << " ";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
