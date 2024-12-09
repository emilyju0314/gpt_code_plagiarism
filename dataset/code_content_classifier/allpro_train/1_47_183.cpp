#include <bits/stdc++.h>
using namespace std;
int n;
string s1, s2, a, b;
int main() {
  cin >> s1 >> s2;
  cin >> n;
  for (int i = 1; i <= n + 1; i++) {
    cin >> a >> b;
    cout << s1 << " " << s2 << endl;
    if (a == s1) {
      s1 = b;
    } else {
      s2 = b;
    }
  }
}
