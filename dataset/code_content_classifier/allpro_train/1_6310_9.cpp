#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

const int INF = INT_MAX / 4;

int n, l, k;

class Edge
{
public:
    int to, cost;
    Edge(int to0, int cost0){
        to = to0;
        cost = cost0;
    }
};

class Data
{
public:
    int pos, ball, rank;
    Data(int pos0, int ball0, int rank0){
        pos = pos0;
        ball = ball0;
        rank = rank0;
    }
    int toInt(){
        return pos + n * (ball + (1<<l) * rank);
    }
};

int main()
{
    for(;;){
        int m;
        cin >> n >> m >> l >> k;
        if(n == 0)
            return 0;

        vector<vector<Edge> > edges(n);
        for(int i=0; i<m; ++i){
            int u, v, c;
            cin >> u >> v >> c;
            -- u;
            -- v;
            edges[u].push_back(Edge(v, c));
            edges[v].push_back(Edge(u, c));
        }

        int start, goal;
        cin >> start >> goal;
        -- start;
        -- goal;

        vector<int> ball(n);
        for(int i=0; i<l; ++i){
            int b;
            cin >> b;
            -- b;
            ball[b] = 1 << i;
        }

        multimap<int, Data> mm;
        vector<int> dp(n*(1<<l)*k, INF);
        mm.insert(make_pair(0, Data(start, ball[start], 0)));
        dp[Data(start, ball[start], 0).toInt()] = 0;

        while(!mm.empty()){
            int cost = mm.begin()->first;
            Data d = mm.begin()->second;
            mm.erase(mm.begin());

            if(cost > dp[d.toInt()])
                continue;

            for(unsigned i=0; i<edges[d.pos].size(); ++i){
                int cost2 = cost + edges[d.pos][i].cost;
                Data d2 = d;
                d2.pos = edges[d.pos][i].to;
                d2.ball |= ball[d2.pos];

                for(int j=0; j<k; ++j){
                    d2.rank = j;
                    if(cost2 < dp[d2.toInt()]){
                        mm.insert(make_pair(cost2, d2));
                        swap(cost2, dp[d2.toInt()]);
                    }
                }
            }
        }

        int ret = dp[Data(goal, (1<<l)-1, k-1).toInt()];
        if(ret == INF)
            cout << "NA" << endl;
        else
            cout << ret << endl;

    }
}