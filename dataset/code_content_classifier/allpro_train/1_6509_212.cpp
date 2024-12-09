#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    bool isSame = true;
    string str;
    cin >> str;
    for (int j = 1; j < str.length(); j++) {
      if (str[j - 1] == str[j])
        continue;
      else
        isSame = false;
    }
    if (isSame)
      cout << str << endl;
    else {
      if (str.length() <= 2)
        cout << str << endl;
      else {
        string testStr = str;
        int one0Count = 0;
        int zero1Count = 0;
        while (str.find("10") != string::npos) {
          one0Count += 1;
          str[str.find("10")] = ' ';
          str[str.find("10") + 1] = ' ';
        }
        while (str.find("01") != string::npos) {
          zero1Count += 1;
          str[str.find("01")] = ' ';
          str[str.find("01") + 1] = ' ';
        }
        if (zero1Count > one0Count) {
          int num2 = str.length() - zero1Count;
          for (int k = 0; k < num2 - 1; k++) cout << "01";
          cout << "01" << endl;
        } else if (zero1Count <= one0Count) {
          int num2 = str.length() - one0Count;
          for (int l = 0; l < num2 - 1; l++) cout << "10";
          cout << "10" << endl;
        }
      }
    }
  }
}
