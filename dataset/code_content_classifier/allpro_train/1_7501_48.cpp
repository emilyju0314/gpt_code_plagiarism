#include <bits/stdc++.h>
using namespace std;
pair<int, int> pos, tpos;
set<pair<int, int> > ps;
int main(void) {
  pos.first = 0;
  pos.second = 0;
  ps.insert(pos);
  string command;
  cin >> command;
  for (int i = 0; i < (int)command.length(); i++) {
    if (command[i] == 'L') pos.second--;
    if (command[i] == 'U') pos.first++;
    if (command[i] == 'R') pos.second++;
    if (command[i] == 'D') pos.first--;
    if (ps.count(pos) == 1) {
      cout << "BUG" << endl;
      return 0;
    }
    if (command[i] != 'L') {
      tpos = pos;
      tpos.second++;
      if (ps.count(tpos) == 1) {
        cout << "BUG" << endl;
        return 0;
      }
    }
    if (command[i] != 'U') {
      tpos = pos;
      tpos.first--;
      if (ps.count(tpos) == 1) {
        cout << "BUG" << endl;
        return 0;
      }
    }
    if (command[i] != 'R') {
      tpos = pos;
      tpos.second--;
      if (ps.count(tpos) == 1) {
        cout << "BUG" << endl;
        return 0;
      }
    }
    if (command[i] != 'D') {
      tpos = pos;
      tpos.first++;
      if (ps.count(tpos) == 1) {
        cout << "BUG" << endl;
        return 0;
      }
    }
    ps.insert(pos);
  }
  cout << "OK" << endl;
  return 0;
}
