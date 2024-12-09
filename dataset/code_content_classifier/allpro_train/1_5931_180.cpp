#include <bits/stdc++.h>
using namespace std;
bool is_open(char a) { return (a == '(' || a == '<' || a == '{' || a == '['); }
bool is_closed(char a) {
  return (a == ')' || a == '>' || a == '}' || a == ']');
}
int main() {
  string S;
  int n, i, answer = 0;
  list<char> L;
  cin >> S;
  n = S.length();
  bool m = true;
  for (i = 0; i < n; i++) {
    if (is_open(S[i]))
      L.push_back(S[i]);
    else if (is_closed(S[i])) {
      if (!L.empty()) {
        if (S[i] == ')') {
          if (L.back() != '(') ++answer;
          L.pop_back();
        } else if (S[i] == ']') {
          if (L.back() != '[') ++answer;
          L.pop_back();
        } else if (S[i] == '}') {
          if (L.back() != '{') ++answer;
          L.pop_back();
        } else if (S[i] == '>') {
          if (L.back() != '<') ++answer;
          L.pop_back();
        }
      } else {
        m = false;
        break;
      }
    }
  }
  if (!L.empty()) {
    m = false;
  }
  if (m)
    cout << answer << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}
