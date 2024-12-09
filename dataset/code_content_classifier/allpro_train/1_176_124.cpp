#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
set<int> s1;
int arr[MAXN];
map<int, int> m1;
int righti[MAXN];
int ans;
int z1, o1, z2, o2;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string a = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      z1++;
    } else {
      o1++;
    }
  }
  if (z1 != o1) {
    cout << 1 << endl;
    cout << s << endl;
    return 0;
  }
  z1 = 0;
  o1 = 0;
  for (int i = 0; i < n; i++) {
    a += s[i];
    if (s[i] == '0') {
      z1++;
    } else {
      o1++;
    }
    string b = "";
    for (int j = i + 1; j < n; j++) {
      if (s[j] == '0') {
        z2++;
      } else {
        o2++;
      }
      b += s[j];
    }
    if (z1 != o1 && z2 != o2) {
      cout << 2 << endl;
      cout << a << " " << b << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  cout << s << endl;
}
