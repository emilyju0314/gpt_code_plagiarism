#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[8];
  int count = 0;
  cin >> str;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == 'A') count++;
    if (str[i] >= '2' && str[i] <= '9') count += (str[i] - '0');
    if (str[i] == '1' && str[i + 1] == '0') count += 10;
  }
  cout << count << endl;
  return 0;
}