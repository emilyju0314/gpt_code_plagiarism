#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)

const int maxn = 101, maxm = 5500,INF = 11100;

int cost[maxn][maxn];
int mincost[maxn];
bool used[maxn];
int n,m,a,b;

int main()
{
    while(cin>> n >> m &&(n&&m))
    {
        memset(cost,INF,sizeof(cost));
        memset(used,false,sizeof(used));
        memset(mincost,INF,sizeof(mincost));

        REP(m)
        {
            cin >> a >> b ;
            cin >>cost[a][b];
            cost[b][a] = cost[a][b];

        }
        mincost[0] = 0;
        int ans = 0;

        while(true)
        {
            int minv = -1;
            REP(n)if(!used[i] &&(minv == -1 ||mincost[i] < mincost[minv] )) minv = i;
            //cout << "v" << minv << endl;
            if(minv == -1) break;
            used[minv] = true;
            ans += mincost[minv];
            //cout<<minv<<":" << mincost[minv] << endl;
            
            REP(n) mincost[i] = min(mincost[i], cost[minv][i]);
        }
        
        cout << ans << endl;

    }

    return 0;
}