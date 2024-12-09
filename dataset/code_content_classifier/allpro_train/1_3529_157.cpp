#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,k,i;
  cin>>a>>b>>k;
  vector<int> d;
  for(i=1;i<=max(a,b);i++)
  {
    if(a%i==0 && b%i==0) d.push_back(i);
  }
  cout<<d[d.size()-k];
  return 0;
}