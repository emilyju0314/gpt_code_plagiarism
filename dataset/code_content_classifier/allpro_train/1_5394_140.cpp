#include <bits/stdc++.h>
using namespace std;
string s;
long long int NUMBER(long long int su, long long int se) {
  long long int num = 0, n = 1;
  if (s[su] == '0' && su != se) return -1;
  for (long long int i = se; i >= su; i--) {
    num = num + (n * (s[i] - '0'));
    n = n * 10;
    if (num > 1000000) return -1;
  }
  return num;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int mx = -1;
  cin >> s;
  if (s.size() < 3) {
    cout << mx << endl;
    return 0;
  }
  for (long long int i = 0; i < s.size() - 2; i++) {
    for (long long int j = i + 1; j < s.size() - 1; j++) {
      long long int n1 = NUMBER(0, i);
      long long int n2 = NUMBER(i + 1, j);
      long long int n3 = NUMBER(j + 1, s.size() - 1);
      if (n1 != -1 && n2 != -1 && n3 != -1) {
        mx = max(mx, n1 + n2 + n3);
      }
    }
  }
  cout << mx << endl;
}
