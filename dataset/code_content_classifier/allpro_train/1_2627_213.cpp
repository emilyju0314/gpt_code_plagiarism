#include <bits/stdc++.h>
using namespace std;
vector<string> parameters(string s) {
  int n = s.size();
  vector<string> res;
  int start = false;
  string temp = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      if ((int)temp.size() != 0) {
        res.push_back(temp);
        temp = "";
      }
      continue;
    }
    if (s[i] == ')') {
      if ((int)temp.size() != 0) {
        res.push_back(temp);
        temp = "";
      }
      break;
    }
    if (s[i] == ' ' || s[i] == ',') {
      if ((int)temp.size() != 0) {
        res.push_back(temp);
        temp = "";
      }
    } else {
      temp += s[i];
    }
  }
  vector<string> ans;
  if (res[0] != "void") ans.push_back(res[0]);
  for (int i = 1; i < res.size(); i++) ans.push_back(res[i]);
  return ans;
}
vector<string> SortVaribles(string s) {
  int n = s.size();
  vector<string> res;
  string temp = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == ' ') {
      if ((int)temp.size() != 0) {
        res.push_back(temp);
        temp = "";
      }
    } else {
      temp += s[i];
    }
  }
  if ((int)temp.size() != 0) {
    res.push_back(temp);
  }
  return res;
}
map<string, string> mapped;
int isSuitable(vector<string> fir, vector<string> sec) {
  if (fir.size() != sec.size()) return false;
  if (fir[0] != sec[0]) return false;
  for (int i = 1; i < fir.size(); i++) {
    if (fir[i] == "T")
      continue;
    else {
      string s = mapped[sec[i]];
      if (fir[i] != s) return false;
    }
  }
  return true;
}
int main() {
  int nFunctions, variables, calls;
  scanf("%d\n", &nFunctions);
  vector<vector<string> > functions;
  for (int i = 0; i < nFunctions; i++) {
    string s;
    getline(cin, s);
    vector<string> temp = parameters(s);
    functions.push_back(temp);
  }
  scanf("%d\n", &variables);
  for (int i = 0; i < variables; i++) {
    string s;
    getline(cin, s);
    vector<string> temp = SortVaribles(s);
    mapped[temp[1]] = temp[0];
  }
  scanf("%d\n", &calls);
  for (int i = 0; i < calls; i++) {
    string s;
    getline(cin, s);
    vector<string> temp = parameters(s);
    int ans = 0;
    for (int j = 0; j < functions.size(); j++) {
      if (isSuitable(functions[j], temp)) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
