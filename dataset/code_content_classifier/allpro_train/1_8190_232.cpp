#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, cntA = 0, cntD = 0;
  cin >> n;
  string str;
  cin >> str;
  for (long long i = 0; i < str.size(); i++) {
    if (str[i] == 'A')
      cntA++;
    else
      cntD++;
  }
  if (cntA == cntD)
    cout << "Friendship";
  else if (cntA > cntD)
    cout << "Anton";
  else
    cout << "Danik";
  return 0;
}
