#include<bits/stdc++.h>
using namespace std;


int main(){
  int H,R;
  cin >> H >> R;

  if(H + R > 0){
    cout << 1 << endl;
  }else if(H < 0 && H + R == 0){
    cout << 0 << endl;
  }else if(H + R < 0){
    cout << -1 << endl;
  }
  
  return 0;
}

