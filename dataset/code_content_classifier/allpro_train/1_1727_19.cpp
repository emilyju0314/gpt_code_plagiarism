#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long LL;

int main(){
    int N;
    while(cin >> N) {
        vector<int> M(N);
        vector<int> L(N);
        vector<vector<int>> child(N);
        vector<int> degree(N);
        
        REP(i, N) {
            cin >> M[i] >> L[i];
            if(L[i] != -1) {
                child[ L[i] ].push_back(i);
                degree[ L[i] ]++;
            }
        }

        queue<int> que;
        REP(i, N) if(degree[i] == 0) que.push(i);

        vector<LL> cost(N);
        vector<int> weight(N);
        
        while(!que.empty()) {
            int u = que.front(); que.pop();
            if(L[u] != -1 && --degree[ L[u] ] == 0) {
                que.push(L[u]);
            }
            vector<int> ws;
            cost[u] = 0;
            for(int c : child[u]) {
                ws.push_back(weight[c]);
                cost[u] += cost[c];
            }
            sort(ws.begin(), ws.end());
            LL tmp = 0;
            for(int w : ws) {
                cost[u] += tmp;
                tmp += w;
            }
            weight[u] = M[u] + accumulate(ws.begin(), ws.end(), 0LL);
        }

        LL ans = 0;
        REP(u, N) if(L[u] == -1) ans += cost[u];
        cout << ans << endl;
    }
    return 0;
}