#include <iostream>

using namespace std;

int main(){
  int s = 0;
  for(int i=0;i<3;i++){
    int in;
    cin >> in;
    s <<= 1;
    s |= in;
  }
  if(s == 4 || s == 2 || s == 0) cout << "Close" << endl;
  if(s == 6 || s == 1) cout << "Open" << endl;
}