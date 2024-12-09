#include <iostream>
#include <string>
using namespace std;

int charToInt(char c) {
  return (int)c - (int)'0';
}

void showSoroban(string num) {
  string str = "00000";
  for(int i = 0; i < num.length(); i++) {
    str[i+5-(int)num.length()] = num[i];
  }
  for(int i = 0; i < str.length(); i++) {
    if(charToInt(str[i]) >= 5) cout << ' ';
    else                       cout << '*';
  }
  cout << endl;
  for(int i = 0; i < str.length(); i++) {
    if(charToInt(str[i]) >= 5) cout << '*';
    else                       cout << ' ';
  }
  cout << endl;
  for(int i = 0; i < str.length(); i++) cout << '=';
  cout << endl;
  for(int n = 0; n < 5; n++) {
    for(int i = 0; i < str.length(); i++) {
      if(charToInt(str[i])%5 == n) cout << ' ';
      else                         cout << '*';
    }
    cout << endl;
  }
}

int main() {
  string str;
  int i = 0;
  while(cin >> str) {
    if(i != 0) cout << endl;
    showSoroban(str);
    i++;
  }
  return 0;
}