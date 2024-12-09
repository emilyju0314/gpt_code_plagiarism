#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,s=0;
	    cin>>n;
	    ll a[n];
	    map <ll, ll> mp;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(mp.find(a[i]-i)!= mp.end())
	           s+=mp[a[i]-i];
	        mp[a[i]-i]++;
	    }
	    
	    cout<<s<<endl;
	}
	return 0;
}
