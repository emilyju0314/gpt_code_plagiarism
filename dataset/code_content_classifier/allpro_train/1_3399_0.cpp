#include<bits/stdc++.h>
#define ll long long
#define inf 333
using namespace std;
int dis[100005];
int t[202], y[202];
ll x[202];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++)dis[i]= inf;

    for(int i=1; i<=n; i++)
    {
        scanf("%d %lld %d", &t[i], &x[i], &y[i]);
        if(t[i]==1)
        {
            if(!(x[i]%100000ll))x[i]/= 100000ll;
            else x[i]= (x[i]/100000ll)+1ll;
        }
    }

    for(int i=1; i<=n; i++)
    {
        vector<int>vec;
        for(int j=0; j<m; j++)
        if(dis[j]!=inf)
        {
            ll sum= j;
            for(int k=0; k<y[i]; k++)
            {
                if(t[i]==1)sum+= x[i];
                else
                {
                    sum*= x[i];
                    if(!(sum%100000ll))sum/= 100000ll;
                    else sum= (sum/100000ll)+1ll;
                }

                if(sum<=m && dis[sum]==inf)vec.push_back(sum);
                else break;
            }
        }
        for(int j=0; j<vec.size(); j++)dis[ vec[j] ]= i;
    }

    for(int i=1; i<=m; i++)
    if(dis[i]==inf)dis[i]= -1;

    for(int i=1; i<=m; i++)
    printf("%d ", dis[i]);puts("");

    return 0;
}
