#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll>mp;
int main()
{
   for(ll i=1;i<=10000;i++)
   {
      mp[i*i*i]=1;
   }
   int t;
   cin >> t;
   while (t--)
   {
   ll n;
   cin>>n;
   int f=0;
   for(ll i=1;i<=10000;i++)
   {
      if(mp[n-i*i*i]==1)
      {
         f=1;
         break;
      }
   }
   if(f==1)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
   }
   return 0;
}


 		 	    	   	   			   	 	