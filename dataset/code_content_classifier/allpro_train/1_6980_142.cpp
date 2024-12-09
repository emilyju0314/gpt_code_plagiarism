#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, int> fr;
  for (int i = 0; i < s.length(); ++i) {
    fr[s[i]]++;
  }
  vector<int> fact;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) fact.push_back(i);
  }
  reverse(fact.begin(), fact.end());
  for (int i = 0; i < fact.size(); ++i) {
    int len = fact[i];
    int maxOdd;
    if (len & 1)
      maxOdd = n / len;
    else
      maxOdd = 0;
    int countOdd = 0;
    for (auto it : fr) {
      if (it.second & 1) countOdd++;
    }
    if (maxOdd >= countOdd) {
      vector<vector<char> > palin(n / len, vector<char>(len, ' '));
      int mid = len / 2;
      if (len & 1) {
        for (int j = 0; j < n / len; ++j) {
          for (int l = 0; l < mid; ++l) {
            char ch;
            for (auto &it : fr) {
              if (it.second != 0 && (it.second >= 2)) {
                it.second -= 2;
                ch = it.first;
                break;
              }
            }
            palin[j][l] = ch;
            palin[j][len - l - 1] = ch;
          }
          int flag = 0;
          char ch;
          for (auto &it : fr) {
            if (it.second & 1) {
              it.second -= 1;
              ch = it.first;
              flag = 1;
              break;
            }
          }
          if (flag) {
            palin[j][mid] = ch;
          } else {
            for (auto &it : fr) {
              if (it.second) {
                it.second -= 1;
                ch = it.first;
                break;
              }
            }
            palin[j][mid] = ch;
          }
        }
      } else {
        for (int j = 0; j < n / len; ++j) {
          for (int l = 0; l < mid; ++l) {
            char ch;
            for (auto &it : fr) {
              if (it.second != 0) {
                it.second -= 2;
                ch = it.first;
                break;
              }
            }
            palin[j][l] = ch;
            palin[j][len - l - 1] = ch;
          }
        }
      }
      cout << n / len << endl;
      for (int j = 0; j < n / len; ++j) {
        for (int l = 0; l < palin[j].size(); ++l) {
          cout << palin[j][l];
        }
        cout << " ";
      }
      return 0;
    }
  }
  return 0;
}
