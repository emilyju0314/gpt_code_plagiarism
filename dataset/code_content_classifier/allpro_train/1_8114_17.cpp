#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
const int mod = 998244353;
const ll INF = -(ll)1e10;

int main()
{
    int n, q;
    cin>>n>>q;
    ll ans = (n-2) * 1LL * (n-2);
    set<pii> row = {{n, n}};
    set<pii> col = {{n, n}};
    while(q--)
    {
        int x, y;
        cin>>x>>y;
        if(x==1)
        {
            pii it = *row.lower_bound({y, -1});
            ans-=(it.ss - 2);
            col.insert({it.ss, y});
        }
        else
        {
            pii it = *col.lower_bound({y, -1});
            ans-=(it.ss - 2);
            row.insert({it.ss, y});
        }
    }
    cout<<ans<<endl;
}