#include<bits/stdc++.h>
using namespace std;

int main(){
  string w; cin >> w;
  sort(w.begin(),w.end());
  bool judge=true;
  for(int i=0; i<w.size(); i=i+2){
    if(w[i]==w[i+1]) continue;
    else judge=false;
  }  
  cout << ( judge ? "Yes" : "No" ) << endl;
  return 0;
}