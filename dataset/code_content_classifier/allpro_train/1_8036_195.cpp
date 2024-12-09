#include<bits/stdc++.h>
using namespace std;

int main() {
  int h, w, s = 0;
  cin >> h >> w;
  int k = h * w;
  char c;
  for(int i = 0;i < k;i++) {
    cin >> c;
    if(c == '#') s++;
  }
  cout << ((s == h + w - 1) ? "Possible" : "Impossible") << endl;
}