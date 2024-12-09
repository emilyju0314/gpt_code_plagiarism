#include <bits/stdc++.h>
using namespace std;
int main() {
  int br, bl, gl, gr;
  cin >> gl >> gr >> bl >> br;
  if ((bl >= (gr - 1) && bl <= (2 * gr + 2)) ||
      (br >= (gl - 1) && br <= (2 * gl + 2))) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
