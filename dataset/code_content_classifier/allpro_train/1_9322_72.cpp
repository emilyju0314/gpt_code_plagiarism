#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;
int main() {
  cin >> s1 >> s2 >> s3;
  for (int i = 0; i < s3.size(); i++) {
    for (int j = 0; j < s1.size(); j++) {
      if (s3[i] + 32 == s1[j]) {
        s3[i] = (s2[j] - 32);
        break;
      } else if (s3[i] == s1[j]) {
        s3[i] = s2[j];
        break;
      }
    }
  }
  cout << s3;
}
