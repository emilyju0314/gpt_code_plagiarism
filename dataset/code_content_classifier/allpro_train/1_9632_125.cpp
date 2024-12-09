#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string a = "";
  string b = "";
  for (int i = 0; i < 300; i++) {
    a += 'a';
    b += 'b';
  }
  cout << a << endl;
  int q1;
  cin >> q1;
  if (q1 == 0) return 0;
  cout << b << endl;
  int q2;
  cin >> q2;
  if (q2 == 0) return 0;
  int n = 600 - q1 - q2;
  int numa = q2 - 300 + n;
  int numb = q1 - 300 + n;
  if (numa == 0) {
    string s = "";
    for (int i = 0; i < n; i++) s += 'b';
    cout << s << endl;
    int x;
    cin >> x;
    return 0;
  }
  if (numb == 0) {
    string s = "";
    for (int i = 0; i < n; i++) s += 'a';
    cout << s << endl;
    int x;
    cin >> x;
    return 0;
  }
  int curr = numb;
  string s = "";
  for (int i = 0; i < n; i++) s += 'a';
  for (int i = 0; i < n - 1; i++) {
    s[i] = 'b';
    cout << s << endl;
    int x;
    cin >> x;
    if (x == 0) return 0;
    if (x < curr) {
      curr = x;
      continue;
    }
    s[i] = 'a';
    curr = x;
  }
  s[n - 1] = 'b';
  cout << s << endl;
  int x;
  cin >> x;
}
