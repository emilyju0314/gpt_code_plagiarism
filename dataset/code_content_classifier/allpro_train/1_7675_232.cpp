#include <bits/stdc++.h>
using namespace std;
int n, m;
string str[105];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str[i];
    int sig = 0;
    for (int j = 0; j < i; j++)
      if (str[j] == str[i]) {
        cout << "YES\n";
        sig = 1;
        break;
      }
    if (!sig) cout << "NO\n";
  }
  return 0;
}
