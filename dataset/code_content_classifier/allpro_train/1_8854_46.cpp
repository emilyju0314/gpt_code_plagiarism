#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string name[n];
  int v[n][3];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++) v[i][j] = 0;
  int m1 = 0;
  int m2 = 0;
  int m3 = 0;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s >> name[i];
    for (int j = 0; j < s; j++) {
      char c1, c2, c3, c4, c5, c6, x;
      cin >> c1 >> c2 >> x >> c3 >> c4 >> x >> c5 >> c6;
      if (c1 == c2 && c2 == c3 && c3 == c4 && c4 == c5 && c5 == c6)
        v[i][0]++;
      else if (c1 > c2 && c2 > c3 && c3 > c4 && c4 > c5 && c5 > c6)
        v[i][1]++;
      else
        v[i][2]++;
    }
    if (v[i][0] > m1) m1 = v[i][0];
    if (v[i][1] > m2) m2 = v[i][1];
    if (v[i][2] > m3) m3 = v[i][2];
  }
  vector<string> taxi, pizza, girls;
  for (int i = 0; i < n; i++) {
    if (v[i][0] == m1) taxi.push_back(name[i]);
    if (v[i][1] == m2) pizza.push_back(name[i]);
    if (v[i][2] == m3) girls.push_back(name[i]);
  }
  cout << "If you want to call a taxi, you should call: " << taxi[0];
  for (unsigned int i = 1; i < taxi.size(); i++) cout << ", " << taxi[i];
  cout << ".\n";
  cout << "If you want to order a pizza, you should call: " << pizza[0];
  for (unsigned int i = 1; i < pizza.size(); i++) cout << ", " << pizza[i];
  cout << ".\n";
  cout << "If you want to go to a cafe with a wonderful girl, you should call: "
       << girls[0];
  for (unsigned int i = 1; i < girls.size(); i++) cout << ", " << girls[i];
  cout << ".\n";
  return 0;
}
