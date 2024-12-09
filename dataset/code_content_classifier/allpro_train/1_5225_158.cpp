#include <bits/stdc++.h>
using namespace std;
stack<char> s;
string a;
int main() {
  cin >> a;
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '(') s.push('(');
    if (a[i] == ')' && !s.empty()) {
      sum = sum + 2;
      s.pop();
    }
  }
  cout << sum;
  return 0;
}
