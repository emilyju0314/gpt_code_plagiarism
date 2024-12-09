#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n,m;
    string s,t;
    cin>>n>>m;
    cin>>s>>t;
    //try to maximise the difference between some element 
    //iterate over all the positions to find the maximum
    //at a position if we want it to be maximum then all entries from 1 to pos must be filled as early as
    //possible and from pos+1 to m as late as possible. we can find this greedily
    vector<int>first(m),last(m);
    int idx=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[idx])
        {
            first[idx]=i;
            idx++;
        }
    }
    idx=(m-1);
    for(int i=(n-1);i>=0;i--)
    {
        if(s[i]==t[idx])
        {
            last[idx]=i;
            idx--;
        }
    }
    int ans=0;
    for(int i=0;i<(m-1);i++)
    {
        ans=max(ans,last[i+1]-first[i]);
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}