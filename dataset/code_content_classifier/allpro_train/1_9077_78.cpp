#include <iostream>

using namespace std;

typedef long long ll;
ll gcd(ll a, ll b){
  return (b > 0)? gcd(b, a %b):a ;
}
int main(){
  ll a, b;
  while(cin >> a >> b){
    ll _gcd = gcd(a, b);
    cout << _gcd << " " << a*b/_gcd << endl;
  }
  return 0;
}