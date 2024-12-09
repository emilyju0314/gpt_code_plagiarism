#include <bits/stdc++.h>
using namespace std;
int main() {
  int k = 0;
  int ladder = 0;
  string slogan;
  cin >> k >> ladder;
  cin >> slogan;
  int h = k / 2;
  if (ladder != 1 && ladder != k) {
    if (ladder > h) {
      while (ladder != k) {
        cout << "RIGHT" << endl;
        ladder++;
      }
    } else if (ladder <= h) {
      while (ladder != 1) {
        cout << "LEFT" << endl;
        ladder--;
      }
    }
  }
  string toPrint = ladder == 1 ? "RIGHT" : "LEFT";
  if (toPrint == "LEFT") {
    string reversed = "";
    for (int i = k - 1; i >= 0; i--) {
      reversed += slogan.at(i);
    }
    slogan = reversed;
  }
  for (int i = 0; i < k; i++) {
    if (i != 0) {
      cout << toPrint << endl;
    }
    cout << "PRINT " << slogan.at(i) << endl;
  }
  return 0;
}
