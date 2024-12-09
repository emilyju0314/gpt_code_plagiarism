#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,sum=0,count=0;
  cin>>n;
   ll min=LONG_MAX;
  ll arr[n];
  	for(ll i=0;i<n;i++)
    {
		ll no;
      cin>>no;
      if(no<=0)
        	count++;
      if(abs(no)<min)
        	min=abs(no);
      sum+=abs(no);
    }
  	sum-=(count%2==1)?(2*min):0;
  	cout<<sum;
}