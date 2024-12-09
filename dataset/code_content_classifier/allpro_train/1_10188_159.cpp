#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int result = 0;
  int hour = (s[0] - '0') * 10 + (s[1] - '0');
  int minute = (s[3] - '0') * 10 + (s[4] - '0');
  int hourNum1 = hour / 10;
  int hourNum2 = hour % 10;
  int minuteNum1 = minute / 10;
  int minuteNum2 = minute % 10;
  while (hourNum1 != minuteNum2 || hourNum2 != minuteNum1) {
    if (minute < 60) {
      if (minute == 59) {
        if (hour == 23) {
          result++;
          hour = 00;
          minute = 00;
        } else {
          result++;
          hour++;
          minute = 00;
        }
      } else {
        result++;
        minute++;
      }
    }
    hourNum1 = hour / 10;
    hourNum2 = hour % 10;
    minuteNum1 = minute / 10;
    minuteNum2 = minute % 10;
  }
  cout << result << endl;
  return 0;
}
