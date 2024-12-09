#include <bits/stdc++.h>
using namespace std;
int main() {
  string time;
  string sleep_length;
  cin >> time;
  cin >> sleep_length;
  int t = 0;
  int l = 0;
  for (int i = 0; i < time.length(); i++) {
    if (i == 0) {
      t += 600 * (time[i] - '0');
    }
    if (i == 1) {
      t += 60 * (time[i] - '0');
    }
    if (i == 3) {
      t += 10 * (time[i] - '0');
    }
    if (i == 4) {
      t += time[i] - '0';
    }
  }
  for (int i = 0; i < sleep_length.length(); i++) {
    if (i == 0) {
      l += 600 * (sleep_length[i] - '0');
    }
    if (i == 1) {
      l += 60 * (sleep_length[i] - '0');
    }
    if (i == 3) {
      l += 10 * (sleep_length[i] - '0');
    }
    if (i == 4) {
      l += sleep_length[i] - '0';
    }
  }
  int bed_time = t - l;
  if (bed_time < 0) {
    bed_time += 60 * 24;
  }
  if (bed_time / 60 < 10) {
    cout << "0";
  }
  cout << bed_time / 60 << ":";
  if (bed_time % 60 < 10) {
    cout << "0";
  }
  cout << bed_time % 60 << endl;
  return 0;
}
