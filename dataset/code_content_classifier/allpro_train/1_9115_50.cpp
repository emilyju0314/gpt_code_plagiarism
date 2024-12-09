#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool chk(string s, ll k)
{
    bool f = true;
    for(ll i = 0; i < k; i++)
    {
        if(s[i] != s[s.size() - 1 - i])
        {
            f = false;
            break;
        }
    }
    return f;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        ll n, k;
        cin>>n>>k;
        cin>>s;
        if(k == 0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(n % 2 == 0 && k == (n/2))
        {
            cout<<"NO"<<endl;
            continue;
        }

        if(chk(s, k)== 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
