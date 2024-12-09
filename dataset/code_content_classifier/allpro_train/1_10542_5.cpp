#include<bits/stdc++.h>
#define ll long long
using  namespace std;

int main(){
   ll n,a,b;
   cin>>n>>a>>b;
   cout<<n/(a+b)*a+min(a,n%(a+b));
}
