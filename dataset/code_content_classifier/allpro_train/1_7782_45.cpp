#include <iostream>
using namespace std;

int main(){
  int a, b;
  while((cin >> a >> b), a, b){
    if(a*b%2==0)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}