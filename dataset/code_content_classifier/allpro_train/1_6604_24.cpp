#include<bits/stdc++.h>
using namespace std;
int main(){
   int t,n;
   cin>>t;
   while(t--){
       cin>>n;
       cout<<(int)((sqrt(2*n-1)+1)/2)-1<<"\n";
   }
}