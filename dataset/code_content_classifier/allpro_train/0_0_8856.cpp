#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> actions(n);
    for(int i = 0; i < n; i++) {
        cin >> actions[i];
    }
    
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    vector<int> result(n, 0);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(actions[i] == 2 && indegree[i] == 0) {
            result[i] = 1;
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int state = q.front();
        q.pop();
        
        for(int next : graph[state]) {
            if(actions[next] == 1) {
                result[next] = 1;
            } else if(actions[next] == 2) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}