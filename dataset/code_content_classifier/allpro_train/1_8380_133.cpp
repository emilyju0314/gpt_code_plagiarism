#include <bits/stdc++.h>
using namespace std;

int main(){
  int m,d;
  cin >> m >> d;
  int ans = 0;
  for(int x = 2; x<=9; x++){
    for(int y = 2; y<=9; y++){
      if(x*y <= m && 10*x + y <= d){
        ans++; 
      }
    }
  }  
  cout << ans << endl;
}
