#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  vector<string> v;
  int max1 = 0;
  while (getline(cin, s)) {
    v.push_back(s);
    if (max1 < s.size()) max1 = s.size();
  }
  max1 = max1 + 2;
  vector<string>::iterator it;
  int i, index;
  for (i = 0; i < max1; i++) cout << "*";
  cout << endl;
  max1 = max1 - 2;
  int flag = 0;
  for (it = v.begin(); it != v.end(); it++) {
    int len = (*it).size();
    if ((max1 - len) % 2 == 0)
      index = (max1 - len) / 2;
    else
      index = (max1 - len - 1) / 2;
    cout << "*";
    if (flag == 0)
      for (i = 1; i <= index; i++) cout << " ";
    else
      for (i = 1; i <= index + (max1 - len) % 2; i++) cout << " ";
    for (i = 0; i < len; i++) cout << (*it)[i];
    if (flag == 0)
      for (i = 1; i <= index + (max1 - len) % 2; i++) cout << " ";
    else
      for (i = 1; i <= index; i++) cout << " ";
    cout << "*";
    if ((max1 - len) % 2 != 0) flag = !flag;
    cout << endl;
  }
  max1 = max1 + 2;
  for (i = 0; i < max1; i++) cout << "*";
  cout << endl;
}
