#include <iostream>
using namespace std;
int main(void){
    int n,m,i,k;
    cin>>n>>m;
    i=n;
    int A[i];
   for(i=0;i<n;i++){
       cin>>A[i];
   }
   
   for(k=1;k<=m;k++){
   for(i=1;i<n;i++){
   if(A[i-1]%k>A[i]%k){
         int temp;
         temp=A[i-1];
         A[i-1]=A[i];
         A[i]=temp;
       }
   }
   }
  for(i=0;i<n;i++){
      cout<<A[i]<<endl;
  }  
}
