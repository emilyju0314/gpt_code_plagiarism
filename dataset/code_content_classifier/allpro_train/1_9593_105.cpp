#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)

#define NMAX 200000
vector<int> b[NMAX];
_LL sum[NMAX];
_LL c[NMAX];
_LL cc[NMAX];
_LL totalcount = 0;
 
void search(int current, int p)
{
    _LL index = 1;
    _LL pcc = cc[c[current]] + totalcount;
    totalcount++;

    for( auto itr = b[current].begin(); itr != b[current].end(); itr++ )
    {
        if( *itr != p ) 
        {
            cc[c[current]] = -totalcount;
            search(*itr, current);
            _LL subc = cc[c[current]] + totalcount;
            sum[c[current]] += subc * (subc + 1) / 2;
        }
    }

    cc[c[current]] = pcc - totalcount;
}
 
int main()
{
    _LL n;
    cin >> n;
    rep(i, n) 
    {
        cin >> c[i];
        c[i]--;
    }
    rep(i, n) sum[i] = 0;
    rep(i, n) cc[i] = 0;
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        b[u].push_back(v);
        b[v].push_back(u);
    }
    search(0, -1);
    rep(i, n)
    {
            _LL subc = cc[i] + totalcount;
            sum[i] += subc * (subc + 1) / 2;  
    }

    _LL total = n * (n + 1) / 2;

    rep(i, n) cout << total - sum[i] << endl;
    
}