#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long k;
  string str = "1";
  for (int i = 2; i < 10000; i++) str = str + to_string(i);
  cin >> k;
  cout << str[k - 1];
  return 0;
}
