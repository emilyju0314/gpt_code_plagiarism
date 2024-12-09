#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
  cin >> a >> b;
  int size = b.size();
  int counter = 0;
  int x, start, end;
  start = -1;
  end = -1;
  x = a.find(b, 0);
  while (x != string::npos) {
    if (start == -1 || end < x) {
      counter++;
      start = x;
      end = x + size - 1;
    } else {
      start = x;
    }
    x = a.find(b, x + 1);
  }
  cout << counter << endl;
}
