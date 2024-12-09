#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
  ll t;
  cin>>t;
  while(t--){
     ll n;
     cin>>n;
     char a[n][n];
     ll f=1,r1,r2,c1,c2;
     for(ll i=0;i<n;i++){
       for(ll j=0;j<n;j++){
         cin>>a[i][j];
         if(a[i][j]=='*'&&f==1){
            r1=i;
            c1=j;
            f++;
         }
         if(a[i][j]=='*'&&f==2){
            r2=i;
            c2=j;
         }
       }
     }
     if(r1==r2){
       if(r1+1<n){
       a[r1+1][c1]='*';
       a[r2+1][c2]='*';
     }
     else{
       a[r1-1][c1]='*';
       a[r2-1][c2]='*';
     }
     }
     else if(c1==c2){
       if(c1+1<n){
       a[r1][c1+1]='*';
       a[r2][c2+1]='*';
     }
     else{
       a[r1][c1-1]='*';
       a[r2][c2-1]='*';
     }
     
     }
     else{
       a[r1][c2]='*';
       a[r2][c1]='*';
     }
     for(ll i=0;i<n;i++){
       for(ll j=0;j<n;j++){
         cout<<a[i][j];
         
       }
       cout<<"\n";
      }
     }  
  return 0;
}