#include <bits/stdc++.h>
using namespace std;
vector<string> names;
int sum = 0;
int main() {
  string str;
  while (getline(cin, str)) {
    if (str[0] == '+')
      names.push_back(str);
    else if (str[0] == '-') {
      str[0] = '+';
      for (int i = 0; i < names.size(); i++)
        if (names[i] == str) names.erase(names.begin() + i);
    } else {
      int size = str.size(), n;
      for (int i = 0; i < str.size(); i++)
        if (str[i] == ':') n = i;
      ++n;
      size -= n;
      int result = (names.size() * size);
      sum += result;
    }
  }
  cout << sum << endl;
  return 0;
}
