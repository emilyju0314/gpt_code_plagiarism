#include <bits/stdc++.h>
using namespace std;
int arr[3] = {0, 1, 2};
string strs[3];
string canonical(string &s) {
  string r = "";
  for (int i = 0; i < s.size(); ++i) {
    if (isalpha(s[i])) r += tolower(s[i]);
  }
  return r;
}
int main() {
  for (int i = 0; i < 3; ++i) {
    cin >> strs[i];
    strs[i] = canonical(strs[i]);
  }
  int N;
  cin >> N;
  while (N--) {
    string s;
    cin >> s;
    s = canonical(s);
    bool ACC = 0;
    do {
      string x = "";
      for (int i = 0; i < 3; ++i) x += strs[arr[i]];
      if (x == s) {
        ACC = 1;
        break;
      }
    } while (next_permutation(arr, arr + 3));
    sort(arr, arr + 3);
    if (ACC)
      cout << "ACC" << endl;
    else
      cout << "WA" << endl;
  }
}
