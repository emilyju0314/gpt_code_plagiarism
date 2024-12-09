#include <bits/stdc++.h>
using namespace std;
int main() {
  setlocale(LC_ALL, "RUS");
  int n;
  string str, strX;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> strX;
    str += strX;
    str += ' ';
  }
  cout << 6 - n << endl;
  if (str.find("purple") == string::npos) cout << "Power" << endl;
  if (str.find("green") == string::npos) cout << "Time" << endl;
  if (str.find("blue") == string::npos) cout << "Space" << endl;
  if (str.find("orange") == string::npos) cout << "Soul" << endl;
  if (str.find("red") == string::npos) cout << "Reality" << endl;
  if (str.find("yellow") == string::npos) cout << "Mind" << endl;
  return 0;
}
