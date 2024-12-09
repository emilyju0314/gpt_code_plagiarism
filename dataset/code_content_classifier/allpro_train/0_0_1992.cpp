#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> canColorTree(int N, vector<vector<int>>& edges) {
    vector<int> result(N, 0);
    vector<vector<int>> adjList(N+1);

    for(auto edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    for(int k = 1; k <= N; k++) {
        vector<int> color(N+1, -1);
        queue<int> q;
        q.push(1);
        color[1] = 0;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int next : adjList[curr]) {
                if(color[next] != -1) continue;
                color[next] = 1 - color[curr]; // alternate colors
                q.push(next);
            }
        }

        bool valid = true;
        for(int i = 1; i <= N; i++) {
            for(int j = i+1; j <= N; j++) {
                if(abs(i-j) % k == 0 && color[i] != color[j]) {
                    valid = false;
                    break;
                }
                if(abs(i-j) % k != 0 && color[i] == color[j]) {
                    valid = false;
                    break;
                }
            }
            if(!valid) break;
        }

        result[k-1] = valid ? 1 : 0;
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> edges(N-1, vector<int>(2));
    for(int i = 0; i < N-1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = canColorTree(N, edges);

    for(int i = 0; i < N; i++) {
        cout << result[i];
    }

    return 0;
}