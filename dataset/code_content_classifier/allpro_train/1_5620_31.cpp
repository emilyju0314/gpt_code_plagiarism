#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

string f(string s) {
  string r;
  for(char c:s){
    if('a' <= c && c <= 'z')
      r += c + 'A' - 'a';
    else if ('A' <= c && c <= 'Z')
      r += c;
  }
  return r;
}

int main() {
  string s;
  getline(cin, s);
  while(cin) {
    s = f(s);
    int n = s.size();
    int dp[1024][1024];
    REP(i,n)
      REP(j,n){
        if (i==j)
          dp[i][i] = 1;
        else
          dp[i][j] = 0;
      }
    for(int i = n - 1; i >= 0; --i) {
      for(int j = i+1; j < n; ++j) {
        if (j==i+1) {
          if(s[i] == s[j]) dp[i][j] = 1;
        } else {
          if (dp[i+1][j-1] && s[i] == s[j]) dp[i][j] = 1;
        }
      }
    }
    vector<int> palind(n*2, 0);
    REP(i,n){
      for(int j = i+2; j < n; ++j) {
        if (dp[i][j] == 1) {
          palind[i+j] = max(palind[i+j] ,j - i + 1);
        }
      }
    }
    set<string> invalid;
    set<string> res;
    REP(i,n*2){
      if (palind[i]) {
        int st = (i - palind[i] + 1) / 2;
        string str = s.substr(st, palind[i]);
        if (invalid.find(str) == end(invalid)) {
          res.insert(s.substr(st, palind[i]));
          for (int j = 1; j * 2 < palind[i]; ++j) {
            string sub = str.substr(j, palind[i] - j * 2);
            invalid.insert(sub);
            if (res.find(sub) != end(res)) {
              res.erase(sub);
            }
          }
        }
      }
    }
    int cnt = 0;
    for(const string& str : res) {
      if(cnt) cout << ' ';
      cout << str;
      ++cnt;
    }
    cout << endl;
    getline(cin, s);
  }
  return 0;
}