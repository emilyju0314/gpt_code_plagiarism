#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n,ans=0;
cin >>n;

for(long long int i=1;i<=pow(n,0.5);i++){
if((n-i)%i==0 && (n-i)>i*i)ans+=(n-i)/i;
}
cout <<ans <<endl;
}
