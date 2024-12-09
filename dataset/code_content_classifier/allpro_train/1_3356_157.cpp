#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, x; cin >> a >> b >> x;
  
  cout << ( (a <= x && a+b >= x) ? "YES" : "NO") << endl;
}