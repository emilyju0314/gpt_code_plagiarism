#include <bits/stdc++.h>
using namespace std;
const int MN = 210000;
int a[MN];
int mark[MN], n, con;
vector<int> l[MN];
vector<vector<int> > l2;
vector<vector<int> > l3;
vector<int> ac[MN];
vector<int> ac2[MN];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  cerr << "HERE" << endl;
  int ef = 0;
  for (int i = 0; i < n; i++) {
    if (!mark[i] && a[i] != i) {
      l[ef].push_back(i);
      mark[i] = 1;
      int state = a[i];
      while (state != i) {
        l[ef].push_back(state);
        mark[state] = 1;
        state = a[state];
      }
      cerr << l[ef].size() << "#" << endl;
      ef++;
    }
  }
  cerr << "2" << endl;
  for (int i = 0; i < ef; i++) {
    while (l[i].size() > 5) {
      for (int j = 0; j < 5; j++) {
        ac[con].push_back(l[i][l[i].size() - j - 1]);
        ac2[con].push_back(l[i][l[i].size() - ((j - 1 + 5) % 5) - 1]);
      }
      con++;
      for (int j = 0; j < 4; j++) {
        l[i].pop_back();
      }
    }
    if (l[i].size() == 2) {
      l2.push_back(l[i]);
      continue;
    }
    if (l[i].size() == 3) {
      l3.push_back(l[i]);
      continue;
    }
    if (l[i].size() == 4) {
      for (int j = 0; j < 4; j++) {
        ac[con].push_back(l[i][l[i].size() - j - 1]);
        ac2[con].push_back(l[i][l[i].size() - (j - 1 + 4) % 4 - 1]);
      }
      con++;
    }
    if (l[i].size() == 5) {
      for (int j = 0; j < 5; j++) {
        ac[con].push_back(l[i][l[i].size() - j - 1]);
        ac2[con].push_back(l[i][l[i].size() - (j - 1 + 5) % 5 - 1]);
      }
      con++;
    }
  }
  cerr << "3" << endl;
  for (int i = 0; i < l3.size(); i++) {
    if (l2.size() > 0) {
      for (int j = 0; j < 3; j++) {
        ac[con].push_back(l3[i][l3[i].size() - j - 1]);
        ac2[con].push_back(l3[i][l3[i].size() - (j - 1 + 3) % 3 - 1]);
      }
      int p = l2.size() - 1;
      for (int j = 0; j < 2; j++) {
        ac[con].push_back(l2[p][l2[p].size() - j - 1]);
        ac2[con].push_back(l2[p][l2[p].size() - (j + 1) % 2 - 1]);
      }
      con++;
      l2.pop_back();
    } else {
      if (i < int(l3.size()) - 2) {
        for (int j = 0; j < 3; j++) {
          ac[con].push_back(l3[i][l3[i].size() - j - 1]);
          ac2[con].push_back(l3[i][l3[i].size() - (j - 1 + 3) % 3 - 1]);
        }
        for (int j = 0; j < 2; j++) {
          ac[con].push_back(l3[i + 1][l3[i + 1].size() - j - 1]);
          ac2[con].push_back(l3[i + 1][l3[i + 1].size() - (1 - j) - 1]);
        }
        l3[i + 1].pop_back();
        con++;
        int p = i + 2;
        for (int j = 0; j < 3; j++) {
          ac[con].push_back(l3[p][l3[p].size() - j - 1]);
          ac2[con].push_back(l3[p][l3[p].size() - (j - 1 + 3) % 3 - 1]);
        }
        p = i + 1;
        for (int j = 0; j < 2; j++) {
          ac[con].push_back(l3[p][l3[p].size() - j - 1]);
          ac2[con].push_back(l3[p][l3[p].size() - (j + 1) % 2 - 1]);
        }
        con++;
        i += 2;
      } else {
        for (int j = 0; j < 3; j++) {
          ac[con].push_back(l3[i][l3[i].size() - j - 1]);
          ac2[con].push_back(l3[i][l3[i].size() - (j - 1 + 3) % 3 - 1]);
        }
        con++;
      }
    }
  }
  for (int i = l2.size() - 1; i >= 1; i -= 2) {
    for (int j = 0; j < 2; j++) {
      ac[con].push_back(l2[i][l2[i].size() - j - 1]);
      ac2[con].push_back(l2[i][l2[i].size() - (1 - j) - 1]);
    }
    for (int j = 0; j < 2; j++) {
      ac[con].push_back(l2[i - 1][l2[i - 1].size() - j - 1]);
      ac2[con].push_back(l2[i - 1][l2[i - 1].size() - (1 - j) - 1]);
    }
    con++;
  }
  if (l2.size() % 2 == 1) {
    int p = 0;
    for (int j = 0; j < 2; j++) {
      ac[con].push_back(l2[p][l2[p].size() - j - 1]);
      ac2[con].push_back(l2[p][l2[p].size() - (1 - j) - 1]);
    }
    con++;
  }
  cout << con << endl;
  for (int i = 0; i < con; i++) {
    cout << ac[i].size() << endl;
    for (int j = 0; j < ac[i].size(); j++) {
      cout << ac[i][j] + 1 << " ";
    }
    cout << endl;
    for (int j = 0; j < ac2[i].size(); j++) {
      cout << ac2[i][j] + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
