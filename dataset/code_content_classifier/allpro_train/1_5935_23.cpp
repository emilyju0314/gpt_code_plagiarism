#include <bits/stdc++.h>
using namespace std;
int main() {
  char dir[100];
  int dist;
  int pos = 0;
  int n;
  cin >> n;
  bool flag = true;
  while (n--) {
    scanf("%d %s", &dist, dir);
    if (pos % 20000 == 0) {
      if (dir[0] == 'E' || dir[0] == 'W') {
        flag = false;
      }
    }
    if (dir[0] == 'E' || dir[0] == 'W') continue;
    if (dir[0] == 'S') {
      if (pos < 20000 && pos + dist > 20000) {
        flag = false;
      }
      if (pos >= 20000 && pos - dist < 20000) {
        flag = false;
      }
      if (pos < 20000)
        pos += dist;
      else
        pos -= dist;
    }
    if (dir[0] == 'N') {
      if (pos < 20000 && pos - dist < 0) {
        flag = false;
      }
      if (pos >= 20000 && pos + dist > 40000) {
        flag = false;
      }
      if (pos < 20000)
        pos -= dist;
      else
        pos += dist;
    }
    if (pos >= 40000) pos = pos % 40000;
  }
  if (flag) {
    if (pos == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
