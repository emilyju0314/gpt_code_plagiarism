#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> colors(n+1, 0);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool possible = true;

    for(int i = 1; i <= n; i++){
        if(colors[i] == 0){
            queue<int> q;
            q.push(i);
            colors[i] = 1;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(int neighbor : graph[curr]){
                    if(colors[neighbor] == 0){
                        colors[neighbor] = 3 - colors[curr];
                        q.push(neighbor);
                    } else if(colors[neighbor] == colors[curr]){
                        possible = false;
                        break;
                    }
                }

                if(!possible) break;
            }
        }

        if(!possible) break;
    }

    if(possible){
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++){
            cout << colors[i] << " ";
        }
    } else {
        cout << "NO";
    }

    return 0;
}