#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  string a, b;
  cin >> a >> b;
  if (a == b)
    printf("-1\n");
  else
    cout << max(a.size(), b.size()) << endl;
  return 0;
}
