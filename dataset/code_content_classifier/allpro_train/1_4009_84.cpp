#include<bits/stdc++.h>
using namespace std;
#include<cstring>
#include<vector>
typedef long long int ll;
typedef long double ld;
typedef double db;

int main()
{           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll tt;cin>>tt;

    for(ll ii=0;ii<tt;ii++)
    {
   ll n,k;cin>>n>>k;
   ll a[n];
    for(ll i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    if(  k==0 )
    {
        for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    } cout<<endl;
    }

   else  if( n<=2 && k!=0 )
    {
        cout<<-1<<endl;
    }
    else {
    ll p=n%2==0?n/2-1:n/2;
    if( p<k  )
    {
        cout<<-1<<endl;
    }
    else
    { ll t=0;
        for(ll i=n-1;i>=0;i=i-2  )
        {
            swap( a[i],a[i-1]  );t++;
            if(t==k ){break; }
        }
        for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    } cout<<endl;
    }

    }

    }
return 0;
}
