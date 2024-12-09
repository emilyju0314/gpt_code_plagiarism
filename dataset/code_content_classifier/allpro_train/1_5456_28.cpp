#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
vector<ll>now,nextt;

int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll val;
        scanf("%lld",&val);
        now.push_back(val);
    }
    nextt.push_back(now[0]);
    for(ll i=1;i<now.size();i++)
    {
        if(now[i]==nextt[nextt.size()-1])continue;
        else nextt.push_back(now[i]);
    }
    for(ll i=0;i<nextt.size();i++){if(i>0)printf(" ");cout<<nextt[i];}
    printf("\n");
    return 0;
}


