#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
#define ll long long
typedef pair <int,int> ii;
const int max6 = 1e6+6;
const int oo = 1e9+9;
const ll inf = 1e18+18;
//////////////////////////

int a[max6];
int b[max6];
int mark[max6];

int t,n;

bool ok(int x)
{
    for (int i = 1; i <= x; ++i)
    {
        int j = n-x+i;
        if (a[i] > b[j])
            return false;
    }

    return true;
}

bool okk(int x)
{
    for (int i = 1; i <= x; ++i)
    {
        int j = n-x+i;
//        if (x == 3)
//            cerr<<"FOUND " <<a[j]<<" "<<b[i]<<"\n";
        if (b[i] > a[j])
            return false;
    }

    return true;
}

//////////////////////////
int main() {
#define file //""
#ifndef ONLINE_JUDGE
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);
#endif // ONLINE_JUDGE

    cin >> t;

    while (t -- )
    {
        cin >> n;

        for (int i = 1; i <= 2*n; ++i)
            mark[i] = 0;

        for (int i = 1; i <= n; ++i)
            {
                cin >> a[i];
                mark[a[i]] = 1;
            }

        int cnt = 0;
        for (int i = 1; i <= 2*n; ++i)
            if (mark[i] == 0)
                b[++cnt] = i;

        int hi = n+1;
        int lo = -1;

        while (hi-lo > 1)
        {
            int mid = (hi+lo)/2;
            if (ok(mid))
                lo = mid;
            else hi = mid;
        }

//        cerr<<lo<<" ";

        for (int i = 0; i <= n; ++i)
            mark[i] = 0;

        for (int i = 0; i <= lo; ++i)
        mark[i]++;

        hi = n+1;
        lo = -1;

        while (hi-lo > 1)
        {
            int mid = (hi+lo)/2;
            if (okk(mid))
                lo = mid;
            else hi = mid;
        }
//        cerr<<lo<<"\n";

        for (int i = 0; i <= lo; ++i)
            mark[n-i]++;
        int res = 0;
        for (int i = 0; i <= n; ++i)
            res += mark[i] == 2;

        printf("%d\n",res);
    }
}
