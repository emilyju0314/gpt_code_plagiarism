//2021 April 10 RAJIV HARLALKA
#include <bits/stdc++.h>
#define ll long long
#define en "\n"
#define f first
#define s second
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        ll sum=0;
        ll a,b;
        map<ll,ll> m;
        for(ll i=0;i<n;i++)
        {

            cin>>v[i];
            if(i==0)
            {
                a=v[i];
                m[a]++;
            }
            if(v[i]!=a)
            {
                    b=v[i];
                    m[b]++;
            }
            else
            m[a]++;
        }
        if(m[a]>m[b])
        {
            for(ll i=0;i<n;i++)
            {
                if(v[i]==b)
                {cout<<i+1<<"\n";break;}

            }
        }
        else
        {for(ll i=0;i<n;i++)
            {
                if(v[i]==a)
                {cout<<i+1<<"\n";break;}

            }}
        

    }
}
