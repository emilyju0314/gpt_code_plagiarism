#include<bits/stdc++.h>
using namespace std;

int main(){
  long X;
  long i;
  cin >> X;
  for(i=1; i<=X; i++){
    if(i*(i+1)/2>=X) break;
  }
  cout << i << endl;
  return 0;
}