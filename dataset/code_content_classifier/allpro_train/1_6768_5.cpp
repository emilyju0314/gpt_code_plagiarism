#include <bits/stdc++.h>
using namespace std;
const int num = 1000003;
int main() {
  string s = "";
  string data[] = {"1000", "1001", "1010", "1011",
                   "1100", "1101", "1110", "1111"};
  string temp = "";
  long long ans = 0;
  int hitung = 0;
  cin >> temp;
  int len = temp.length();
  for (int i = 0; i < len; i++) {
    s = "";
    hitung = 0;
    switch (temp[i]) {
      case '>':
        s += data[0];
        break;
      case '<':
        s += data[1];
        break;
      case '+':
        s += data[2];
        break;
      case '-':
        s += data[3];
        break;
      case '.':
        s += data[4];
        break;
      case ',':
        s += data[5];
        break;
      case '[':
        s += data[6];
        break;
      case ']':
        s += data[7];
        break;
    }
    ans *= 16;
    ans %= num;
    for (int j = 0; j < 4; j++) {
      hitung += pow(2, 4 - j - 1) * (s[j] - 48);
    }
    ans += hitung;
    ans %= num;
  }
  cout << ans << endl;
  return 0;
}
