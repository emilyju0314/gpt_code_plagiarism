#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  string l = "";
  for (int i=0; i < W+2; i++){
    l += "#";
  }
  cout << l << endl;
  for (int i=0; i<H; i++){
    string s;
    cin >> s;
    cout << "#" << s << "#" << endl;
  }
  cout << l << endl;
  
}
    