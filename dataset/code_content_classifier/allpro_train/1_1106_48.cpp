#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int k=n%10;
  if(k==3)  cout<<"bon";
  else if(k==0||k==1||k==6||k==8) cout<<"pon";
  else cout<<"hon";
  return 0;
}