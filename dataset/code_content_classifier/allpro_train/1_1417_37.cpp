#include <bits/stdc++.h>
using namespace std;
int n;
string s, type, type1;
stack<int> st;
int main() {
  cin >> n;
  getline(cin, s);
  int i, I;
  for (i = 0; i < n; i++) {
    getline(cin, s);
    int begin = 0;
    while ((begin < s.size()) && (s[begin] == ' ')) {
      begin++;
    }
    if (begin == s.size() - 1) {
      continue;
    }
    if (begin == s.size()) {
      continue;
    }
    string ss = s.substr(begin, 2);
    if (ss == "tr") {
      st.push(i);
    } else {
      if (ss == "th") {
        begin += 5;
        while ((begin < s.size()) && (s[begin] == ' ')) {
          begin++;
        }
        { begin++; }
        while ((begin < s.size()) && (s[begin] == ' ')) {
          begin++;
        }
        while ((begin < s.size()) && (s[begin] != ')') && (s[begin] != ' ')) {
          type += s[begin++];
        }
        I = i;
        break;
      } else {
        st.pop();
      }
    }
  }
  i++;
  for (; i < n; i++) {
    getline(cin, s);
    if (s.size() == 0) {
      continue;
    }
    int begin = 0;
    while ((begin < s.size()) && (s[begin] == ' ')) {
      begin++;
    }
    if (begin == s.size() - 1) {
      continue;
    }
    if (begin == s.size()) {
      continue;
    }
    string ss = s.substr(begin, 2);
    if (ss == "tr") {
      st.push(i);
    } else {
      if (st.top() > I) {
        st.pop();
      } else {
        begin += 5;
        while ((begin < s.size()) && (s[begin] == ' ')) {
          begin++;
        }
        { begin++; }
        while ((begin < s.size()) && (s[begin] == ' ')) {
          begin++;
        }
        type1 = "";
        while ((begin < s.size()) && (s[begin] != ' ') && (s[begin] != ',')) {
          type1 += s[begin++];
        }
        if (type1 == type) {
          while ((begin < s.size()) && (s[begin] != '"')) {
            begin++;
          }
          begin++;
          type = "";
          while ((begin < s.size()) && (s[begin] != '"')) {
            type += s[begin++];
          }
          cout << type << endl;
          exit(0);
        } else {
          st.pop();
        }
      }
    }
  }
  cout << "Unhandled Exception" << endl;
}
