#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  string name[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
  int cnt = 0;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    string key = "";
    switch (str[i]) {
      case 'D':
        key = str.substr(i, 5);
        if (!name[0].compare(key)) cnt++;
        break;
      case 'O':
        key = str.substr(i, 4);
        if (!name[1].compare(key)) cnt++;
        break;
      case 'S':
        key = str.substr(i, 5);
        if (!name[2].compare(key)) cnt++;
        break;
      case 'A':
        key = str.substr(i, 3);
        if (!name[3].compare(key)) cnt++;
        break;
      case 'N':
        key = str.substr(i, 6);
        if (!name[4].compare(key)) cnt++;
        break;
    }
  }
  if (cnt == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
