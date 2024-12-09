#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    
    vector<int> score(N+1, 0);
    vector<vector<pair<int,int>>> edges(N+1, vector<pair<int,int>>());
    for(int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        edges[a].push_back({b, t});
        edges[b].push_back({a, t});
    }

    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});

    vector<bool> visited(N+1, false);
    int totalScore = 0;

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curScore = pq.top().first;
        pq.pop();

        if(visited[curNode]) continue;
        visited[curNode] = true;

        totalScore = max(totalScore, curScore + score[curNode]);

        for(pair<int,int> neigh : edges[curNode]){
            int nextNode = neigh.first;
            int nextTime = neigh.second;

            if(nextTime > T) continue;

            if(!visited[nextNode]){
                score[nextNode] += 1;
                pq.push({curScore+1, nextNode});
            }
        }
    }

    cout << totalScore << endl;

    return 0;
}