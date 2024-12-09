#include<iostream>
using namespace std;


int main() {

  int n ; cin >> n;
  float sum = 0;
  
  for ( int i = 0 ; i < n ; i++) {
  	
    float a; string s; cin >> a >> s ; 
    if ( s == "JPY" ) sum += a;
    else sum+= 380000 * a ;
  }
 cout << sum ; 


}