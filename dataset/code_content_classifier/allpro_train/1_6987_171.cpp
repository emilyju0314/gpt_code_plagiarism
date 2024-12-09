#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,ans;
  cin >>A;
  togo:
 for(int i=2;i<sqrt(A);i++){
   if(A%i==0){
     A++;
     goto togo;
   }
 }
  cout<<A<<endl;
}