#include<bits/stdc++.h>
using namespace std;
const int INF = 100100100;
int used[1000];
int deg[1000];

int dfs(int i, vector<vector<pair<int, int> > > &adj){

    int res = 0;
    int n = (int)adj.size();
    //cout << i << endl;
    for(int j = 0; j < adj[i].size(); j++){
        if(deg[adj[i][j].second] != 1 && used[adj[i][j].second] == false){
            used[adj[i][j].second] = true;
            res = max(res, dfs(adj[i][j].second, adj) + adj[i][j].first);
            used[adj[i][j].second] = false;
        }
    }

    //cout << res << endl;

    return res;
}

int main(){

    while(1){
        int n; cin >> n;
        if(!n) break;
        vector<vector<pair<int, int> > > adj(n);
        memset(deg, 0, sizeof(deg));
        vector<int> p(n - 1);
        vector<int> d(n - 1);
        for(int i = 0; i < n - 1; i++) cin >> p[i];
        for(int i = 0; i < n - 1; i++) cin >> d[i];


        for(int i = 0; i < n - 1; i++){
            adj[i + 1].push_back({d[i], p[i] - 1});
            adj[p[i] - 1].push_back({d[i], i + 1});
            
            //G[i + 1][p[i] - 1] = G[p[i] - 1][i + 1] = d[i];
            deg[i + 1]++;
            deg[p[i] - 1]++;
        }

        int ans = 0;

        //cout << "tya" << endl;

        //deg = 1の頂点をとりのぞく
        for(int i = 0; i < n; i++){

            if(deg[i] == 1){

                for(int j = 0; j < adj[i].size(); j++){
                
                    ans += adj[i][j].first;
                    
                }
            }
        
        }

        //取り除いた後の橋の重みの三倍を足していく
        for(int i = 0; i < n; i++){

            for(int j = 0; j < adj[i].size(); j++){

                if(i >= adj[i][j].second) continue;

                if(deg[i] == 1 || deg[adj[i][j].second] == 1) continue;

                ans += 3 * adj[i][j].first;
            }

        }

        //木の直径を求める
        int dis = 0;

        //cout << "wa" << endl;
        //cout << ans << endl;
        for(int i = 0; i < n; i++){
            if(deg[i] == 1) continue;

            //cout << i << endl;
            memset(used, false, sizeof(used));
            used[i] = true;
            dis = max(dis, dfs(i, adj));
        }

        ans -= dis;
        cout << ans << endl;
    
    }
    
    return 0;
}
