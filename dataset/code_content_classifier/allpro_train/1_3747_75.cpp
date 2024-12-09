#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    if(n==1)cout<<"9";
    else if(n==2)cout<<"98";
    else if(n==3)cout<<"989";
    else
    {
        cout<<"989";
        ll c=0;
        for(ll i=4;i<=n;i++)
        {
            cout<<c;
            ++c;
            if(c==10)c=0;
        }
    }
    cout<<endl;
    }

}
