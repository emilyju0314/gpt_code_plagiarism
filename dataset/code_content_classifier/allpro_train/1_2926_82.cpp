#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
  double a[11],ans;
  while(cin>>a[1]){
   
    ans=a[1];
    for(int i=2;i<11;i++){
      if(i%2){
	a[i]=a[i-1]/3.0;
      }else{
	a[i]=a[i-1]*2.0;
      }
      ans+=a[i];
    }
    printf("%.8f\n",ans);
  }
  return 0;
}