#include <bits/stdc++.h>
using namespace std;

int main(){
  int x , max = 0,h,c = 0;
  cin >> x;
  for(int i = 0;i < x;i++){
    cin >> h;
    if (max <= h){
      c++;
      max = h;
    }
  }
  cout << c << endl;
  
}