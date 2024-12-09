#include <bits/stdc++.h>
using namespace std;
int main() {
  char trash[100];
  int n;
  cin >> n;
  cin.getline(trash, 10);
  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);
    bool fredas = (s.find("lala.", s.length() - 5) == s.length() - 5);
    bool rainbows = (s.find("miao.") == 0);
    if (fredas ^ rainbows) {
      cout << (fredas ? "Freda's" : "Rainbow's");
    } else {
      cout << "OMG>.< I don't know!";
    }
    cout << endl;
  }
  return 0;
}
