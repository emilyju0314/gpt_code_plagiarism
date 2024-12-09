#include <bits/stdc++.h>
using namespace std;
int main() {
  string strA, strB, strC, strD;
  vector<pair<int, char> > v;
  vector<char> v1, v2;
  cin >> strA >> strB >> strC >> strD;
  v.push_back(make_pair(strA.length() - 2, 'A'));
  v.push_back(make_pair(strB.length() - 2, 'B'));
  v.push_back(make_pair(strC.length() - 2, 'C'));
  v.push_back(make_pair(strD.length() - 2, 'D'));
  int count = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (j == i)
        continue;
      else {
        if (v[i].first / 2 >= v[j].first) count++;
      }
    }
    if (count == 3) v1.push_back(v[i].second);
    count = 0;
  }
  count = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (j == i)
        continue;
      else {
        if (v[i].first * 2 <= v[j].first) count++;
      }
    }
    if (count == 3) v2.push_back(v[i].second);
    count = 0;
  }
  if (v1.size() == 1 && v2.size() != 1) {
    cout << v1[0];
    return 0;
  }
  if (v1.size() != 1 && v2.size() == 1) {
    cout << v2[0];
    return 0;
  } else
    cout << 'C';
  return 0;
}
