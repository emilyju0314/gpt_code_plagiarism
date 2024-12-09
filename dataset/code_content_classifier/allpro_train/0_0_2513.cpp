#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestInstructions(int N, int M, int K, vector<int>& darkRooms, vector<vector<int>>& roads) {
    vector<vector<int>> brightRooms(N);
    
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            brightRooms[roads[j][i] - 1].push_back(j);
        }
    }
    
    vector<int> dist(N, -1);
    queue<int> q;
    
    for (int i = 0; i < M; i++) {
        q.push(darkRooms[i] - 1);
        dist[darkRooms[i] - 1] = 1;
    }
    
    while (!q.empty()) {
        int currentRoom = q.front();
        q.pop();
        
        for (int room : brightRooms[currentRoom]) {
            if (dist[room] == -1) {
                dist[room] = dist[currentRoom] + 1;
                q.push(room);
            }
        }
    }
    
    int minInstructions = *min_element(dist.begin(), dist.end());
    
    return minInstructions;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> darkRooms(M);
    for (int i = 0; i < M; i++) {
        cin >> darkRooms[i];
    }
    
    vector<vector<int>> roads(N, vector<int>(K));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cin >> roads[i][j];
        }
    }
    
    int answer = shortestInstructions(N, M, K, darkRooms, roads);
    cout << answer << endl;
    
    return 0;
}