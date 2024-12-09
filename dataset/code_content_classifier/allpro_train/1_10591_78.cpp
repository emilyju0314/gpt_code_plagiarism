#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n, q; cin>>n>>q;
    string s; cin>>s;

    int a[n+1];

    for(int i=0; i<n; i++)
    {
        a[i+1] = s[i]-96;
    }
    a[0]=0;

    for(int i=0; i<=n; i++ )
        a[i] += a[i-1];

    while(q--)
    {
        int x,y; cin>>x>>y;

        cout<<a[y]-a[x-1]<<"\n";
    }

    return 0;
}

