#include <bits/stdc++.h>
using namespace std;
char result[25];
int idx;
char allSame() {
  if (idx == 7) return 'R';
  if (idx == 56) return 'S';
  if (idx == 56 * 8) return 'P';
  return 'a';
}
int main(void) {
  for (int i = 0; i < 3; i++) {
    cout << "R" << endl;
    cin >> result;
    if (result[0] == 'p') idx |= (1 << i);
  }
  for (int i = 0; i < 3; i++) {
    cout << "S" << endl;
    cin >> result;
    if (result[0] == 'p') idx |= (1 << (i + 3));
  }
  for (int i = 0; i < 3; i++) {
    cout << "P" << endl;
    cin >> result;
    if (result[0] == 'p') idx |= (1 << (i + 6));
  }
  char s = allSame();
  if (s != 'a') {
    for (int i = 0; i < 11; i++) cout << s << endl;
    return 0;
  }
  if (idx < 2) {
    cout << 'S' << endl;
    cout << 'R' << endl;
    cout << 'P' << endl;
    cout << 'S' << endl;
    cout << 'R' << endl;
    cout << 'P' << endl;
    cout << 'S' << endl;
    cout << 'R' << endl;
    cout << 'P' << endl;
    cout << 'S' << endl;
    cout << 'R' << endl;
    return 0;
  }
  if (idx == 72 || idx == 73) {
    cout << 'R' << endl;
    cout << 'S' << endl;
    cout << 'P' << endl;
    cout << 'R' << endl;
    cout << 'S' << endl;
    cout << 'P' << endl;
    cout << 'R' << endl;
    cout << 'S' << endl;
    cout << 'P' << endl;
    cout << 'R' << endl;
    cout << 'S' << endl;
    return 0;
  }
  if (idx >= 256) {
    cout << 'R' << endl;
    cout << 'P' << endl;
    cout << 'S' << endl;
    cout << 'R' << endl;
    cout << 'P' << endl;
    cout << 'S' << endl;
    cout << 'R' << endl;
    cout << 'P' << endl;
    cout << 'S' << endl;
    cout << 'R' << endl;
    cout << 'P' << endl;
    return 0;
  }
  if (idx >= 128) {
    cout << 'S' << endl;
    cout << 'R' << endl;
    cout << 'P' << endl;
    cout << 'S' << endl;
    cout << 'R' << endl;
    cout << 'P' << endl;
    cout << 'S' << endl;
    cout << 'R' << endl;
    cout << 'P' << endl;
    cout << 'S' << endl;
    cout << 'R' << endl;
    return 0;
  }
  cout << 'P' << endl;
  cout << 'S' << endl;
  cout << 'R' << endl;
  cout << 'P' << endl;
  cout << 'S' << endl;
  cout << 'R' << endl;
  cout << 'P' << endl;
  cout << 'S' << endl;
  cout << 'R' << endl;
  cout << 'P' << endl;
  cout << 'S' << endl;
  return 0;
}
