#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t,su=0;
  cin>>t;
  while(t--)
  {
  	int l,r;
  	cin>>l>>r;
  	su+=(r-l)+1;
  }
  cout<<su;
 return 0;
}
