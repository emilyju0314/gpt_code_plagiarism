#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
map<string, int> H1[maxn], H2[maxn];
vector<char> ans;
char getA(string a, string b) {
  int c[30];
  for (int i = 0; i < 26; i++) c[i] = 0;
  for (int i = 0; i < a.size(); i++) c[a[i] - 'a']++;
  for (int i = 0; i < b.size(); i++) c[b[i] - 'a']--;
  for (int i = 0; i < 26; i++) {
    if (c[i] > 0) return i + 'a';
  }
  return 'a';
}
string solve(int n) {
  cout << "? 1 " << n << endl;
  for (int i = 0; i < n * (n + 1) / 2; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    H1[s.size()][s]++;
  }
  cout << "? 2 " << n << endl;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    H2[s.size()][s]++;
  }
  for (int i = 1; i <= n; i++) {
    for (auto p : H2[i]) {
      H1[i][p.first] -= H2[i][p.first];
    }
    for (auto p : H1[i]) {
      if (p.second > 0) {
        string new1 = "";
        for (int j = 0; j < ans.size(); j++) new1 += ans[j];
        ans.push_back(getA(p.first, new1));
      }
    }
  }
  string new1 = "";
  for (int j = 0; j < ans.size(); j++) new1 += ans[j];
  return new1;
}
int ori[26][105];
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "? 1 1" << endl;
    string sss;
    cin >> sss;
    cout << "! " << sss << endl;
  } else if (n == 2) {
    cout << "? 1 1" << endl;
    string sss1, sss2;
    cin >> sss1;
    cout << "? 2 2" << endl;
    cin >> sss2;
    cout << "! " << sss1 << sss2 << endl;
  } else {
    string halfans = solve((n + 1) / 2);
    cout << "? 1 " << n << endl;
    for (int i = 0; i < n * (n + 1) / 2; i++) {
      string sss;
      cin >> sss;
      for (int j = 0; j < sss.size(); j++) {
        ori[sss[j] - 'a'][sss.size()]++;
      }
    }
    string halfans2 = "";
    for (int i = 1; i <= n / 2; i++) {
      for (int j = 0; j < 26; j++) {
        int num = ori[j][1] - (ori[j][i + 1] - ori[j][i]);
        for (int k = 0; k < i; k++) {
          if (halfans[k] - 'a' == j) {
            num--;
          }
        }
        for (int k = 0; k < halfans2.size(); k++) {
          if (halfans2[k] - 'a' == j) {
            num--;
          }
        }
        if (num > 0) {
          halfans2 += ('a' + j);
          break;
        }
      }
    }
    for (int i = 0; i < halfans2.size(); i++) {
      halfans += halfans2[halfans2.size() - 1 - i];
    }
    cout << "! " << halfans << endl;
  }
}
