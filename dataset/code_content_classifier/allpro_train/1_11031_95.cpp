#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> myset;
  set<int>::iterator it;
  string s, tmp;
  int start, pos, left;
  bool flag;
  while (cin >> s) {
    myset.clear();
    while ((pos = s.find(',')) != string ::npos) {
      tmp = s.substr(0, pos);
      myset.insert(atoi(tmp.c_str()));
      s = s.substr(pos + 1);
    }
    tmp = s.substr(0, pos);
    myset.insert(atoi(tmp.c_str()));
    for (flag = false, it = myset.begin(), left = start = *it, ++it;
         it != myset.end(); ++it) {
      if (*it == start + 1) {
        flag = true;
        ++start;
      } else {
        if (flag)
          cout << left << '-' << start << ",";
        else
          cout << start << ",";
        left = start = *it;
        flag = false;
      }
    }
    if (left != start)
      cout << left << '-' << start << endl;
    else
      cout << start << endl;
  }
}
