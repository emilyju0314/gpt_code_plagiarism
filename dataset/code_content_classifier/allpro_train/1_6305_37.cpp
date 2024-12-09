#include <iostream>
using namespace std;
int main(){
  int n;
  while( cin >> n,n ){
    for(int i = 0 ; i < n ; i++){
      double a,b,c;
      cin >> a >> b >> c;
      if(a == 100 || b == 100 || c == 100)cout << "A" <<endl;
      else if((a+b)/2 >= 90)cout << "A" <<endl;
      else if((a+b+c)/3 >= 80)cout << "A" <<endl;
      else if((a+b+c)/3 >= 70)cout << "B" <<endl;
      else if((a+b+c)/3 >= 50 && (a >= 80 || b>=80))cout << "B" <<endl;
      else cout << "C" << endl;
    }
  }
  return 0;
}