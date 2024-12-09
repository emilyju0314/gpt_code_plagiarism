#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
  int a,b,x;
 
  cin >> a >> b >> x;
 
  int cost = 0;
 
  while(x > 0){
    if(x <= 500){
      cost += min(a,b);
      break;
    }
 
    cost += min(a,b*2);
    x -= 1000;
  }
 
  cout << cost << endl;
 
  return 0;
}
