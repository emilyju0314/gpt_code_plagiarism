#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m;
  cin >> n;
  int rem = n % 6;
  cin >> m;
  int pos[] = {0, 0, 0};
  pos[m] = 1;
  if (rem == 0) {
    cout << m;
  } else {
    while (rem > 0) {
      if (rem % 2 == 0)
        swap(pos[1], pos[2]);
      else
        swap(pos[1], pos[0]);
      rem--;
    }
    for (int i = 0; i < 3; i++) {
      if (pos[i]) cout << i;
    }
  }
  return 0;
}
