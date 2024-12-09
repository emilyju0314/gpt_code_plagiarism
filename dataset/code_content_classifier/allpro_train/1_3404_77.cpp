#include <bits/stdc++.h>
using namespace std;
int get() {
  int r = 0;
  scanf("%*[a-zA-Z0-9_]%n", &r);
  return r;
}
bool ask() {
  int e = get();
  if (e < 1 || e > 16) return false;
  if (getchar() != '@') return false;
  int c = 0;
  char p;
  while (c <= 32) {
    int f = get();
    if (f < 1 || f > 16) return false;
    c += f;
    p = getchar();
    if (p == '/' || p == EOF || p == '\n') break;
    if (p != '.') return false;
  }
  if (c > 32) return false;
  if (p == EOF || p == '\n') return true;
  e = get();
  p = getchar();
  if (e < 1 || e > 16 || p != EOF && p != '\n') return false;
  return true;
}
int main() {
  if (ask())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
