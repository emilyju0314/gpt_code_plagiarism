#include<iostream>
using namespace std;

int main(){
  int n,k,c;
  for(;;){
    c=0;
    cin>>n;
    if(!n)break;

    for(int i=0;i<n*(n-1)/2;i++)
      cin>>k,c+=k;

    cout<<c/(n-1)<<endl;
  }
}