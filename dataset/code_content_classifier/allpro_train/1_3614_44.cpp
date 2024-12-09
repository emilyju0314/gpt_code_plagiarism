#include<iostream>
using namespace std;
int main(){
  int a[9], n, b;
  bool c[9];
  string res = "No";
  for(int i=0; i<9; i++){
    cin >> a[i];
    c[i] = false;
  }
  cin >> n;
  for(int j=0; j<n; j++){
    cin >> b;
    for(int i=0; i<9; i++){
      if(a[i] == b){
        c[i] = true;
        break;
      }
    }
  }
  if( c[0]&c[1]&c[2] || c[3]&c[4]&c[5] || c[6]&c[7]&c[8] ) res = "Yes";
  if( c[0]&c[3]&c[6] || c[1]&c[4]&c[7] || c[2]&c[5]&c[8] ) res = "Yes";
  if( c[0]&c[4]&c[8] || c[2]&c[4]&c[6] ) res = "Yes";
  cout << res << endl;
  return 0;
}
