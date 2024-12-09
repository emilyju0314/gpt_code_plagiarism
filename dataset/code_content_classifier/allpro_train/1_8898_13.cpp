#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll i,j,k,n,a,b,x,y,z;
int main()
{
  for(cin>>n,i=n;n!=0;n/=10)a+=n%10;
  cout<<(i%a==0?"Yes":"No")<<endl;
}