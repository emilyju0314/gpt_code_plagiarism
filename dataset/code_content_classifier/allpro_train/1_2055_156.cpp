#include <bits/stdc++.h>
using namespace std;


int main(){
   int a,b,c,d;
  cin>>a>>b>>c>>d;
  int e=(c+b-1)/b;
  int f=(a+d-1)/d;
  if(e <= f) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
  
