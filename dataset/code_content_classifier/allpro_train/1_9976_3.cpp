#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
map<string, int> mp1[maxn], mp2[maxn];
vector<int> ans;
char getA(string a, string b) {
  int c[30];
  for (int i = 0; i < 26; i++) c[i] = 0;
  for (int i = 0; i < a.size(); i++) c[a[i] - 'a']++;
  for (int i = 0; i < b.size(); i++) c[b[i] - 'a']--;
  for (int i = 0; i < 26; i++)
    if (c[i] > 0) return i + 'a';
}
string solve(int n) {
  cout << "? 1 " << n << endl;
  for (int i = 0; i < n * (n + 1) / 2; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    mp1[s.size()][s]++;
  }
  cout << "? 2 " << n << endl;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    mp2[s.size()][s]++;
  }
  for (int i = 1; i <= n; i++) {
    for (auto p : mp2[i]) mp1[i][p.first] -= mp2[i][p.first];
    for (auto p : mp1[i]) {
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
    string s;
    cin >> s;
    cout << "! " << s << endl;
  } else if (n == 2) {
    cout << "? 1 1" << endl;
    string s1, s2;
    cin >> s1;
    cout << "? 2 2" << endl;
    cin >> s2;
    cout << "! " << s1 << s2 << endl;
  } else {
    string ramjas = solve((n + 1) / 2);
    cout << "? 1 " << n << endl;
    for (int i = 0; i < n * (n + 1) / 2; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); j++) ori[s[j] - 'a'][s.size()]++;
    }
    string ramjas2 = "";
    for (int i = 1; i <= n / 2; i++) {
      for (int j = 0; j < 26; j++) {
        int num = ori[j][1] - (ori[j][i + 1] - ori[j][i]);
        for (int k = 0; k < i; k++) {
          if (ramjas[k] - 'a' == j) num--;
        }
        for (int k = 0; k < ramjas2.size(); k++) {
          if (ramjas2[k] - 'a' == j) num--;
        }
        if (num > 0) {
          ramjas2 += ('a' + j);
          break;
        }
      }
    }
    for (int i = 0; i < ramjas2.size(); i++)
      ramjas += ramjas2[ramjas2.size() - 1 - i];
    cout << "! " << ramjas << endl;
  }
}
