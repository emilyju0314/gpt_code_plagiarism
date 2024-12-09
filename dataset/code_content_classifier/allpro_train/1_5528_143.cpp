#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a,b,c,d,cou;
  while(1){
    cin >>a >>b;
    if(b>a)swap(a,b);
    if(a==0&&b==0)break;
    cou=1;
    while(1){
      if(a%b==0)break;
      d=a%b;
      a=b;
      b=d;
      cou++;
    }
    cout <<b<<" "<<cou<<endl;
  }
  return 0;
}