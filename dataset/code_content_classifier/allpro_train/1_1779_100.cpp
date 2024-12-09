#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int sum = 0;
  for (int i = 0; i < str.size(); i++) {
    if ('A' <= str[i] && str[i] <= 'Z') sum += (str[i] - 'A' + 1);
    if ('a' <= str[i] && str[i] <= 'z') sum -= (str[i] - 'a' + 1);
  }
  cout << sum << endl;
  return 0;
}
