#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
  cin>>a>>b;
  if(a==b)
    	cout<<(a+b);
  else
  {
		cout<<2*max(a,b)-1;
  }
}