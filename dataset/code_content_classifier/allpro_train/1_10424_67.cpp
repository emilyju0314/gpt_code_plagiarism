#include <bits/stdc++.h>
using namespace std;
string president[41] = {
    "",         "Washington", "Adams",     "Jefferson", "Madison",
    "Monroe",   "Adams",      "Jackson",   "Van Buren", "Harrison",
    "Tyler",    "Polk",       "Taylor",    "Fillmore",  "Pierce",
    "Buchanan", "Lincoln",    "Johnson",   "Grant",     "Hayes",
    "Garfield", "Arthur",     "Cleveland", "Harrison",  "Cleveland",
    "McKinley", "Roosevelt",  "Taft",      "Wilson",    "Harding",
    "Coolidge", "Hoover",     "Roosevelt", "Truman",    "Eisenhower",
    "Kennedy",  "Johnson",    "Nixon",     "Ford",      "Carter",
    "Reagan"};
int main() {
  int n;
  scanf("%d", &n);
  cout << president[n] << endl;
  return 0;
}
