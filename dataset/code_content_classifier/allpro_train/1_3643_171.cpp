#include <bits/stdc++.h>
using namespace std;
int n, i, f;
string s;
int main() {
  for (cin >> n >> s; i < n - 1 + f; i++)
    f || s[i] <= s[i + 1] ? cout << s[i], 0 : f = 1;
}
